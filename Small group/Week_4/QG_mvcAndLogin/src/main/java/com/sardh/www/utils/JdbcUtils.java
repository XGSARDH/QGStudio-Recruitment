package com.sardh.www.utils;

import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

public class JdbcUtils {

    static InputStream inputStream = null;
    static Properties properties = new Properties();

    //Connect to server
    static {
        try {
            inputStream = JdbcUtils.class.getResourceAsStream("/jdbc.properties");
            // This could throw IOException
            properties.load(inputStream);
            // This could throw ClassNotFoundException
            Class.forName(properties.getProperty("driver"));
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            if (inputStream != null) {
                try {
                    // This could throw IOException
                    inputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    /**
     *  @name        : public static Connection getConnection()throws Exception
     *	@description : Get available connection objects
     *	@param		 : None
     *	@return		 : Connection
     *  @notice      : None
     */
    public static Connection getConnection()throws Exception {
        String url = properties.getProperty("url");
        String username = properties.getProperty("username");
        String password = properties.getProperty("password");
        Connection conn = DriverManager.getConnection(url,username,password);
        return conn;
    }

    /**
     *  @name        : public static void close(ResultSet set, Statement statement,PreparedStatement preparedStatement, Connection connection)throws Exception
     *	@description : Close Connection
     *	@param		 : ResultSet set, Statement statement,PreparedStatement preparedStatement, Connection connection
     *	@return		 : None
     *  @notice      : None
     */
    public static void close(ResultSet set, Statement statement, PreparedStatement preparedStatement, Connection connection)throws Exception {
        if(set != null) {
            set.close();
        }
        if(statement != null) {
            statement.close();
        }
        if(preparedStatement != null){
            preparedStatement.close();
        }
        if(connection != null) {
            connection.close();
        }
    }
}
