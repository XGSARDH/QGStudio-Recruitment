package connectpool;

import java.sql.Connection;

/**
 * 连接池接口
 */
public interface IConnectionPool{
    /**
     * 从连接池中拿取一个连接对象
     * @return
     */
    Connection getConnection();

    /**
     *  把连接对象归还到连接池
     */
    void releaseConnection(Connection connection);
}
