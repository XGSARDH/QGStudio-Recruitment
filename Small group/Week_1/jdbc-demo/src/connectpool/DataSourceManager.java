package connectpool;

import java.sql.Connection;

public class DataSourceManager {
    static DataSourceConfig dataSourceConfig = new DataSourceConfig();
    static ConnectionPool connectionPool = new ConnectionPool(dataSourceConfig);

    /**
     * 从连接池中获取一个连接对象
     * @return
     */
    public static Connection getConnection() {
        return connectionPool.getConnection();
    }

    /**
     * 关闭一个数据库连接(归还到连接池中)
     */
    public static void close(Connection connection) {
        connectionPool.releaseConnection(connection);
    }
}
