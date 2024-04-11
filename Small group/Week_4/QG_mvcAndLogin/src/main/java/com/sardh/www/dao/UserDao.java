package com.sardh.www.dao;

import com.sardh.www.po.User;

import java.util.List;

public interface UserDao {

    // 查找所有用户
    List<User> findAll();

    // 保存用户（新增或更新）
    boolean save(User user);

    // 更新用户信息
    void update(User user);

    // 删除用户
    void delete(String username);

    // 根据用户名查找用户
    User findByUsername(String username);
}
