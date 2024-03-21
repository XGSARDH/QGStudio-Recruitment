package com.xgsardh.util;

import com.sun.jdi.event.StepEvent;

import java.io.IOException;
import java.io.InputStream;
import java.sql.*;
import java.util.Properties;

/**
 * JdbcUtils
 * @Author: xgsardh
 * @Date: 2024.3.19
 */
public class JdbcUtils {
    static InputStream inputStream = null;
    static Properties properties = new Properties();

    //Connect to server
    static {
        try {
            inputStream = JdbcUtils.class.getResourceAsStream("/com/xgsardh/resources/jdbc.properties");
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
     *  @name        : public static Connection getconntion()throws Exception
     *	@description : Get available connection objects
     *	@param		 : None
     *	@return		 : Connection
     *  @notice      : None
     */
    public static Connection getconntion()throws Exception {
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
    public static void close(ResultSet set, Statement statement,PreparedStatement preparedStatement, Connection connection)throws Exception {
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

    /**
     *  @name        : public static int update(String sql, Object... params) throws Exception
     *	@description : Close Connection
     *	@param		 : String sql, Object... params
     *	@return		 : int
     *  @notice      : None
     */
    public static int update(String sql, Object... params) throws Exception {
        Connection conn = null;
        PreparedStatement pstmt = null;
        int count = 0;
        try {
            conn = JdbcUtils.getconntion();
            pstmt = conn.prepareStatement(sql);

            for(int i = 0;i < params.length;i++){
                pstmt.setObject(i+1,params[i]);
            }

            count = pstmt.executeUpdate();

        }catch(Exception e) {
            e.printStackTrace();
        }finally {
            //Release resources
            JdbcUtils.close(null,null,pstmt,conn);
        }
        return count;
    }


}
