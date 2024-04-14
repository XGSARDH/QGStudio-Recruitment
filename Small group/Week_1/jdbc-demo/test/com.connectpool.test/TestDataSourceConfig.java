package com.connectpool.test;

import com.connectpool.DataSourceManager;

import java.sql.Connection;

public class TestDataSourceConfig {
    public static void main(String[] args) {
        Thread1 t = new Thread1();
        for (int i = 0; i < 10; i++){
            new Thread(t, "线程" + i).start();
        }
    }


}

/**
 * 普通测试类
 */
class Thread1 implements Runnable{

    @Override
    public void run() {
        try {
            Connection connection = DataSourceManager.getConnection();
            Thread.sleep(20000);
            DataSourceManager.close(connection);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}