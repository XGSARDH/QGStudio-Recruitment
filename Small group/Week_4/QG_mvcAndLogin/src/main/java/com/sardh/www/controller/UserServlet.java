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
    /**
     * @description: Responsible for login methods
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
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

    /**
     * @description: Responsible for registration methods
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void register(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("application/json;charset=UTF-8");
        UserService userService = new UserServiceImpl();
        String username = request.getParameter("userName");
        String password = request.getParameter("password");
        String phone = request.getParameter("phone");
        int registerStatus = userService.register(username, password, phone);
        if(registerStatus == 1) {
            response.getWriter().write("{\"status\":200, \"message\":\"注册成功\"}");
        } else if(registerStatus == 0) {
            response.getWriter().write("{\"status\":402, \"message\":\"注册失败\"}");
        } else if(registerStatus == 2) {
            response.getWriter().write("{\"status\":201, \"message\":\"注册失败\"}");
        } else {
            response.getWriter().write("{\"status\":202, \"message\":\"注册失败\"}");
        }

    }

    /**
     * @description: Responsible for retrieving password methods
     * @param request
     * @param response
     * @throws ServletException
     * @throws IOException
     */
    public void retrievePassword(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("application/json;charset=UTF-8");
        UserService userService = new UserServiceImpl();
        String username = request.getParameter("userName");
        String password = request.getParameter("toBePassword");
        String phone = request.getParameter("phone");
        System.out.println(username);
        System.out.println(password);
        System.out.println(phone);
        int registerStatus = userService.retrievePassword(username, password, phone);
        System.out.println(registerStatus);
        if(registerStatus == 1) {
            response.getWriter().write("{\"status\":200, \"message\":\"注册成功\"}");
        } else if(registerStatus == 0) {
            response.getWriter().write("{\"status\":402, \"message\":\"注册失败\"}");
        } else {
            response.getWriter().write("{\"status\":201, \"message\":\"注册失败\"}");
        }
    }

}