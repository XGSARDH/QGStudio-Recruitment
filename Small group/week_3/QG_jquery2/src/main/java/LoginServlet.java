

import com.alibaba.fastjson.JSONObject;

import java.io.IOException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 设置响应内容类型为JSON
        resp.setContentType("application/json");
        // 设置字符编码为UTF-8
        resp.setCharacterEncoding("UTF-8");

        // 从请求中获取用户名和密码
        String userName = req.getParameter("userName");
        String password = req.getParameter("password");
        System.out.println("username: " + userName);
        System.out.println("password: " + password);

        // 初始化响应的JSON对象
        JSONObject responseJson;
        responseJson = new JSONObject();

        if ("admin".equals(userName) && "password".equals(password)) {
            // 登录成功
            responseJson.put("status", 200);
            responseJson.put("msg", "登录成功！");
        } else {
            // 登录失败
            responseJson.put("status", 403);
            responseJson.put("msg", "用户名或密码错误！");
        }

        // 将JSON对象作为响应发送
        resp.getWriter().write(responseJson.toString());
    }
}