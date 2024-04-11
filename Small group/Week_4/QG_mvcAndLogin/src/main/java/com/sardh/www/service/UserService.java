package com.sardh.www.service;

public interface UserService {
    boolean login(String username, String password);
    boolean register(String username, String password);
}
