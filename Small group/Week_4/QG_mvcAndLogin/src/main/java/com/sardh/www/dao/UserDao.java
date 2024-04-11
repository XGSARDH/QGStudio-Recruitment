package com.sardh.www.dao;

import com.sardh.www.po.User;

import java.util.List;

public interface UserDao {

    /**
     * @description: Find all users
     * @return
     */
    List<User> findAll();

    /**
     * @description: Save users (new or updated)
     * @param user
     * @return
     */
    boolean save(User user);

    /**
     * @description: Update user information
     * @param user
     */
    void update(User user);

    /**
     * @description: delete user
     * @param username
     */
    void delete(String username);

    /**
     * @description: Find users based on username
     * @param username
     * @return
     */
    User findByUsername(String username);
}
