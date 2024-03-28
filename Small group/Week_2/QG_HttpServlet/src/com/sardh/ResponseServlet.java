package com.sardh;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ResponseServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp);

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp);
    }

    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp);
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        handleRequest(req, resp);
    }

    private void handleRequest(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        // 设置响应内容类型
        resp.setContentType("text/plain");

        // 根据请求方法设置不同的状态码
        String method = req.getMethod();
        switch (method) {
            case "GET":
                resp.setStatus(HttpServletResponse.SC_OK); // 200 OK
                resp.getWriter().println("GET request received. Status 200 OK");
                break;
            case "POST":
                resp.setStatus(HttpServletResponse.SC_FOUND ); // 300 Created
                resp.getWriter().println("POST request received. Status 201 Created");
                break;
            case "PUT":
                resp.setStatus(HttpServletResponse.SC_FORBIDDEN ); // 403 Accepted
                resp.getWriter().println("PUT request received. Status 202 Accepted");
                break;
            case "DELETE":
                resp.setStatus(HttpServletResponse.SC_GATEWAY_TIMEOUT ); // 504 No Content
                resp.getWriter().println("DELETE request received. Status 204 No Content");
                break;
            default:
                resp.setStatus(HttpServletResponse.SC_METHOD_NOT_ALLOWED); // 405 Method Not Allowed
                resp.getWriter().println("Method not supported. Status 405 Method Not Allowed");
                break;
        }
    }


}