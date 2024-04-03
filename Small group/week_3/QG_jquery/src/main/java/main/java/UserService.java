package main.java;

public class UserService {
    // 模拟数据库中的用户名和密码
    private static final String VALID_USER_NAME = "admin";
    private static final String VALID_PASSWORD = "password";

    public User login(String userName, String password) {

        if (VALID_USER_NAME.equals(userName) && VALID_PASSWORD.equals(password)) {
            System.out.println("Login success in UserService");

            return new User(userName, "这里可以填写其他用户信息");
        }

        System.out.println("Login failed in UserService");
        return null;
    }
}
