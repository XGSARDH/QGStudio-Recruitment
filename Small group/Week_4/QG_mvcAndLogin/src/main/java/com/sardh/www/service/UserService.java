package com.sardh.www.service;

public interface UserService {
    boolean login(String username, String password);
    // 0是用户名错,1是密码错,2是正确
    int register(String username, String password, String phone);

    int retrievePassword(String username, String toBePassword, String phone);
}
