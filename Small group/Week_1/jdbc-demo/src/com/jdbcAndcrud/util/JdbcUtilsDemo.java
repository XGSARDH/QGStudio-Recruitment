package com.jdbcAndcrud.util;

import com.jdbcAndcrud.Account;
import org.junit.Test;

import java.sql.Connection;
import java.sql.Statement;

/**
 * @author SARDH
 */
public class JdbcUtilsDemo {
    public static void main(String[] args)throws Exception {
        Connection conn = JdbcUtils.getconntion();

        //3. 定义sql语句
        String sql = "update account set money = 1000 where id = 2";

        //4. 获取执行sql的对象 Statement
        Statement stmt = conn.createStatement();

        //5. 执行sql
        //受影响的行数
        int count = stmt.executeUpdate(sql);

        //6. 处理结果
        System.out.println(count);

        //7. 释放资源
        //先释放后面打开的,后释放先打开的+
        JdbcUtils.close(null,stmt,null,conn);

    }

    @Test
    public void updateTest() throws Exception {

        String sql1 = "insert into account (id,name,money) value (?,?,?)";
        int count1 = CrudUtils.update(sql1,4,"Tom",1000);
        String sql2 = "delete from account where id = ?";
        int count2 = CrudUtils.update(sql2,4);

        //6. 处理结果
        System.out.println(count1);
        System.out.println(count2);

    }

    @Test
    public void queryTest() throws Exception {

        String sql = "select id, name, money from account where id = ?";
        MyHandler<Account> handler = resultSet -> {
            if (resultSet.next()) {
                return new Account(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getInt("money")
                );
            } else {
                //If the query is empty, it will return empty
                return null;
            }
        };

        //Use query to query the user with ID 1
        Account account = CrudUtils.query(sql, handler, 1);
        if (account != null) {
            System.out.println(account);
        } else {
            System.out.println("No person found with the given ID.");
        }

    }

}
