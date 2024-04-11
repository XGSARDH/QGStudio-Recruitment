package com.sardh.www.po;

/**
 * @author SARDH
 */
public class User {
    private String username;
    private String password;

    public User() {
    }

    public User(String userName, String password) {
        this.username = userName;
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String userName) {
        this.username = userName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    @Override
    public String toString() {
        return "User{" +
                ", userName='" + username + '\'' +
                ", password='" + password + '\'' +
                '}';
    }
}
