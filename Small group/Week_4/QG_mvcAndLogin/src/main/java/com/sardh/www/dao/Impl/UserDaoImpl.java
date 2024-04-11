package com.sardh.www.dao.Impl;

import com.sardh.www.dao.UserDao;
import com.sardh.www.po.User;
import com.sardh.www.utils.JdbcUtils;
import org.testng.annotations.Test;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author SARDH
 */
public class UserDaoImpl implements UserDao {

    @Override
    public List<User> findAll() {
        String sql = "SELECT * FROM user";
        List<User> users = new ArrayList<>();

        try (Connection conn = JdbcUtils.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql);
             ResultSet rs = pstmt.executeQuery()) {

            while (rs.next()) {
                User user = new User();
                user.setUsername(rs.getString("username"));
                user.setPassword(rs.getString("password"));
                users.add(user);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return users;
    }

    @Override
    public boolean save(User user) {
        // SQL 语句中的 ON DUPLICATE KEY UPDATE 可以处理主键冲突的情况
        // 这里假设除了username作为主键外，还有其他字段如password等
        String sql = "INSERT INTO user (username, password) VALUES (?, ?)";

        try (Connection conn = JdbcUtils.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            // 设置参数
            pstmt.setString(1, user.getUsername());
            pstmt.setString(2, user.getPassword());

            // 执行更新
            int affectedRows = pstmt.executeUpdate();

            return affectedRows > 0;

        } catch (Exception e) {
            e.printStackTrace();
            // 出现异常时，返回false
            return false;
        }
    }

    @Test
    public void Testsave(){
        UserDao userDao = new UserDaoImpl();
        User user = new User("3","3");
        if(userDao.findByUsername(user.getUsername()) == null){
            System.out.println(userDao.save(user));
        }
        else{
            System.out.println("exist");
        }


    }

    @Override
    public void update(User user) {
        String sql = "UPDATE user SET password = ? WHERE username = ?";


        try (Connection conn = JdbcUtils.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, user.getPassword());
            pstmt.setString(2, user.getUsername());

            pstmt.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void delete(String username) {
        String sql = "DELETE FROM user WHERE username = ?";

        try (Connection conn = JdbcUtils.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            pstmt.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public User findByUsername(String username) {
        String sql = "SELECT * FROM user WHERE username = ?";
        User user = null;

        try (Connection conn = JdbcUtils.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, username);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    user = new User();
                    user.setUsername(rs.getString("username"));
                    user.setPassword(rs.getString("password"));
                }
            }
        } catch (
                Exception e) {
            e.printStackTrace();
        }

        return user;
    }
}
