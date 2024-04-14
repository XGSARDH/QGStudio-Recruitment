package com.connectpool.test;


import com.connectpool.DataSourceConfig;
import org.junit.Test;

/**
 * 读取数据库配置文件,, 封装一个配置类
 */
public class TestDateSourceConfig {
    @Test
    public void test01(){
        DataSourceConfig dataSourceConfig = new DataSourceConfig();
        System.out.println(dataSourceConfig);
    }
}