package com.sardh.www.service;

public interface UserService {
    /**
     *
     * @param username
     * @param password
     * @return
     */
    boolean login(String username, String password);

    /**
     *
     * @param username
     * @param password
     * @param phone
     * @description:Returning 0 is a username error
     *              Return 1 indicates successful registration
     *              Return 2 indicates that the password does not match the format
     *              Return 3 shows that the phone number does not match the format
     * @return
     */
    int register(String username, String password, String phone);

    /**
     *
     * @param username
     * @param toBePassword
     * @param phone
     * @description:  Returning 0 is a user information error
     *                Return 1 indicates successful registration
     *                Return 2 indicates that the password does not match the format
     * @return
     */
    int retrievePassword(String username, String toBePassword, String phone);
}
