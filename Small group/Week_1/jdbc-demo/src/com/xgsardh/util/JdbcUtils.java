package com.xgsardh.util;

import com.sun.jdi.event.StepEvent;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.Properties;

public class JdbcUtils {
    static InputStream inputStream = null;
    static Properties properties = new Properties();

    static{
        try{
            inputStream = JdbcUtils.class.getResourceAsStream("/com/xgsardh/resources/jdbc.properties");
            try {
                properties.load(inputStream);
            }catch (Exception e){
                e.printStackTrace();
            }
            Class.forName(properties.getProperty("driver"));
        }catch (ClassNotFoundException e){
            e.printStackTrace();
        }finally {
            try{
                inputStream.close();
            }catch (IOException e){
                e.printStackTrace();
            }
        }
    }

    // 获取连接
    public static Connection getconntion()throws Exception{
        String url = properties.getProperty("url");
        String username = properties.getProperty("username");
        String password = properties.getProperty("password");
        Connection conn = DriverManager.getConnection(url,username,password);
        return conn;
    }

    // 释放对应资源
    public static void close(ResultSet set, Statement statement, Connection connection)throws Exception {
        if(set != null){
            set.close();
        }
        if(statement != null){
            statement.close();
        }
        if(connection != null){
            connection.close();
        }
    }
}
