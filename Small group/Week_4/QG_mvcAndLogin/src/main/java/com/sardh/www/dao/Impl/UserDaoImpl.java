package com.sardh.www.dao.Impl;

import com.sardh.www.dao.UserDao;
import com.sardh.www.po.User;
import com.sardh.www.utils.JdbcUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
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
                user.setPhone(rs.getString("phone"));
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
        String sql = "INSERT INTO user (username, password, phone) VALUES (?, ?, ?)";

        try (Connection conn = JdbcUtils.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            // 设置参数
            pstmt.setString(1, user.getUsername());
            pstmt.setString(2, user.getPassword());
            pstmt.setString(3, user.getPhone());

            // 执行更新
            int affectedRows = pstmt.executeUpdate();

            return affectedRows > 0;

        } catch (Exception e) {
            e.printStackTrace();
            // 出现异常时，返回false
            return false;
        }
    }

    @Override
    public void update(User user) {
        String sql = "UPDATE user SET password = ?, phone = ? WHERE username = ?";


        try (Connection conn = JdbcUtils.getConnection();
             PreparedStatement pstmt = conn.prepareStatement(sql)) {

            pstmt.setString(1, user.getPassword());
            pstmt.setString(2, user.getPhone());
            pstmt.setString(3, user.getUsername());

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
                    user.setPhone(rs.getString("phone"));
                }
            }
        } catch (
                Exception e) {
            e.printStackTrace();
        }

        return user;
    }
}
