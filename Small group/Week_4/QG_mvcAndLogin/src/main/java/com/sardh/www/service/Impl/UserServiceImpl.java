package com.sardh.www.service.Impl;

import com.sardh.www.controller.UserServlet;
import com.sardh.www.dao.Impl.UserDaoImpl;
import com.sardh.www.dao.UserDao;
import com.sardh.www.po.User;
import com.sardh.www.service.UserService;

public class UserServiceImpl implements UserService {

    @Override
    public boolean login(String username, String password) {
        UserDao userDao = new UserDaoImpl();
        User user = userDao.findByUsername(username);
        if(user == null) {
            return false;
        } else if (!user.getPassword().equals(password)) {
            return false;
        }
        // equal is success
        return true;
    }

    @Override
    public boolean register(String username, String password) {
        UserDao userDao = new UserDaoImpl();
        User user = userDao.findByUsername(username);
        if(user != null) {
            return false;
        }
        user = new User(username,password);
        userDao.save(user);
        return true;
    }

}
