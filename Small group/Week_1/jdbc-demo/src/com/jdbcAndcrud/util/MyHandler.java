package com.jdbcAndcrud.util;


import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author SARDH
 * @param <T>
 */
@FunctionalInterface
public interface MyHandler<T> {
    T handle(ResultSet rs) throws SQLException;

}