package com.sardh.www.controller;

import com.sardh.www.service.Impl.UserServiceImpl;
import com.sardh.www.service.UserService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.Constructor;

public class UserServlet extends BaseServlet{

    public void login(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("application/json;charset=UTF-8");
        UserService userService = new UserServiceImpl();
        String username = request.getParameter("userName");
        String password = request.getParameter("password");
        boolean loginStatus = userService.login(username, password);
        if(loginStatus){
            response.getWriter().write("{\"status\":200, \"message\":\"登录成功\"}");
        } else {
            response.getWriter().write("{\"status\":402, \"message\":\"登录失败\"}");
        }
    }

    public void register(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("application/json;charset=UTF-8");
        UserService userService = new UserServiceImpl();
        String username = request.getParameter("userName");
        String password = request.getParameter("password");
        boolean registerStatus = userService.register(username, password);
        if(registerStatus) {
            response.getWriter().write("{\"status\":200, \"message\":\"注册成功\"}");
        } else {
            response.getWriter().write("{\"status\":402, \"message\":\"注册失败\"}");
        }

    }

}