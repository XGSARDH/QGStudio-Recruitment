package com.xgsardh.util;


import java.sql.ResultSet;
import java.sql.SQLException;

@FunctionalInterface
public interface MyHandler<T> {
    T handle(ResultSet rs) throws SQLException;

}