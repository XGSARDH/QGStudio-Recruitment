package com.sardh.www.service.Impl;

import com.sardh.www.dao.Impl.UserDaoImpl;
import com.sardh.www.dao.UserDao;
import com.sardh.www.po.User;
import com.sardh.www.service.UserService;

public class UserServiceImpl implements UserService {

    @Override
    public boolean login(String username, String password) {
        if("".equals(username)) {
            return false;
        }

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
    public int register(String username, String password, String phone) {
        if("".equals(username)) {
            return 0;
        }
        if(!password.matches("^(?=.*\\d)(?=.*[a-zA-Z])(?=.*[^\\da-zA-Z\\s]).{1,9}")){
            return 2;
        }
        if(!phone.matches("\\d{3}-\\d{8}|\\d{4}-\\d{7}|^1(3[0-9]|4[57]|5[0-35-9]|7[0678]|8[0-9])\\d{8}")){
            return 3;
        }
        UserDao userDao = new UserDaoImpl();
        User user = userDao.findByUsername(username);
        if(user != null) {
            return 0;
        }
        user = new User(username, password, phone);
        userDao.save(user);
        return 1;
    }

    @Override
    public int retrievePassword(String username, String toBePassword, String phone) {
        if("".equals(username)) {
            return 0;
        }
        if(!toBePassword.matches("^(?=.*\\d)(?=.*[a-zA-Z])(?=.*[^\\da-zA-Z\\s]).{1,9}")){
            return 2;
        }
        if(!phone.matches("\\d{3}-\\d{8}|\\d{4}-\\d{7}|^1(3[0-9]|4[57]|5[0-35-9]|7[0678]|8[0-9])\\d{8}")){
            return 0;
        }
        UserDao userDao = new UserDaoImpl();
        User user = userDao.findByUsername(username);
        if(user == null) {
            System.out.println("not exist");
            return 0;
        }else if(!user.getPhone().equals(phone)) {
            System.out.println("phone wrong");
            return 0;
        }
        user = new User(username, toBePassword, phone);
        userDao.update(user);
        return 1;
    }

}
