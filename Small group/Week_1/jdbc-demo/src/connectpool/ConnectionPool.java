package connectpool;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Timer;
import java.util.TimerTask;
import java.util.Vector;
import java.util.concurrent.atomic.AtomicInteger;

public class ConnectionPool implements IConnectionPool {

    private DataSourceConfig dataSourceConfig;

    /**
     * 一个线程安全的集合
     * 一个集合,存储空闲的连接对象
     * ArrayList线程不安全
     */
    Vector<Connection> freePools = new Vector<Connection>();

    /**
     * 一个线程安全的集合
     * 一个集合,存储正在使用的连接对象
     * ArrayList线程不安全
     */
    Vector<ConnectionEntity> usePools = new Vector<ConnectionEntity>();

    AtomicInteger connectionCount = new AtomicInteger(0);

    public ConnectionPool(DataSourceConfig dataSourceConfig) {
        this.dataSourceConfig = dataSourceConfig;
        // 初始化连接池
        init();
    }

    /**
     * 连接池的初始化
     */
    private void init() {
        for (int i = 0; i < Integer.valueOf(dataSourceConfig.getInitSize()); i++) {
            Connection connection = createConnection();
            System.out.println("连接池初始化, 连接对象" + connection);
            freePools.add(connection);
        }
        // 打开健康检查, 防止一直不释放
        if (Boolean.valueOf(dataSourceConfig.getHealth()) == true) {
            //checkConnectionTimeOut();
        }
    }

    private void checkConnectionTimeOut() {
        Worker worker = new Worker();
        // 启动完毕后自动进行
        new Timer().schedule(worker, Long.valueOf(dataSourceConfig.getDelay()));

    }

    class Worker extends TimerTask {
        @Override
        public void run() {
            try {
                System.out.println("定时检查占用时间过长的连接");
                // 遍历正在使用的连接池
                for (int i = 0; i < usePools.size(); i++) {
                    System.out.println("sizes: " + usePools.size());
                    ConnectionEntity connectionEntity = usePools.get(i);
                    if (System.currentTimeMillis() - connectionEntity.getUseStartTime() > Long.valueOf(dataSourceConfig.getWaittime())) {
                        Connection connection = connectionEntity.getConnection();
                        System.out.println("1");
                        if (available(connection)) {
                            System.out.println("2");
                            System.out.println("释放了一个超时连接" + connection);
                            connection.close();
                            usePools.remove(i);
                            connectionCount.decrementAndGet();
                        }
                    }
                }
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }

    /**
     * 创造一个连接
     *
     * @return
     */
    private synchronized Connection createConnection() {
        Connection connection = null;
        try {
            Class.forName(dataSourceConfig.getDriver());
            connection = DriverManager.getConnection(dataSourceConfig.getUrl(), dataSourceConfig.getUsername(), dataSourceConfig.getPassword());
            // 累加+1的意思
            connectionCount.incrementAndGet();
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return connection;
    }

    /**
     * 从连接池获取一个连接对象
     *
     * @return
     */
    @Override
    public Connection getConnection() {
        synchronized (this) {
            try {
                while (freePools.isEmpty()) {
                    if (connectionCount.get() < Integer.valueOf(dataSourceConfig.getMaxSize())) {
                        Connection connection = createConnection();
                        ConnectionEntity connectionEntity = new ConnectionEntity(connection, System.currentTimeMillis());
                        usePools.add(connectionEntity);
                        System.out.println("创建了一个新的连接" + connection);
                        return connection;
                    } else {
                        System.out.println("连接数已经超了总大小, 进行等待"
                                + "空闲连接池大小是: " + freePools.size()
                                + ",正在使用的连接池大小是: " + usePools.size()
                                + ",总连接数为" + connectionCount
                        );
                        this.wait(Integer.valueOf(dataSourceConfig.getWaittime()));
                    }
                }
                Connection connection = freePools.remove(0);
                ConnectionEntity connectionEntity = new ConnectionEntity(connection, System.currentTimeMillis());
                usePools.add(connectionEntity);
                System.out.println("从空闲连接池获取了一个连接" + connection);
                return connection;
            } catch (Exception e) {
                throw new RuntimeException("获取连接时发生错误", e);
            }
        }
    }


    /**
     * 判断连接是否可用
     *
     * @param connection
     * @return
     */
    private boolean available(Connection connection) {
        try {
            if (connection != null && !connection.isClosed()) {
                return true;
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        return false;
    }

    /**
     * 归还一个连接对象
     */
    @Override
    public void releaseConnection(Connection connection) {
        synchronized (this) {
            try {
                if (!connection.isClosed() && connection != null) {
                    // 如果这个连接可用, 放入可用连接池中
                    freePools.add(connection);
                    // 从正在使用的连接的连接池中溢出这个连接
                    ConnectionEntity connectionEntity = null;
                    for (ConnectionEntity usePool : usePools) {
                        if(usePool.getConnection() == connection) {
                            connectionEntity = usePool;
                        }
                    }
                    usePools.remove(connectionEntity);
                    System.out.println("归还了一个连接" + connectionEntity.getConnection()
                            + ",空闲连接池大小是: " + freePools.size()
                            + ",正在使用的连接池大小是: " + usePools.size()
                            + ",总连接数为" + connectionCount
                    );
                    notifyAll();
                }
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
