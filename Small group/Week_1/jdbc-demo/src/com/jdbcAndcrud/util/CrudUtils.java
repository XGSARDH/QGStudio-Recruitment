package com.jdbcAndcrud.util;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class CrudUtils {
    /**
     *  @name        : public static int update(String sql, Object... params) throws Exception
     *	@description : Close Connection
     *	@param		 : String sql, Object... params
     *	@return		 : int
     *  @notice      : None
     */
    public static int update(String sql, Object... params) throws Exception {
        Connection conn = null;
        PreparedStatement pstmt = null;
        int count = 0;
        try {
            conn = JdbcUtils.getconntion();
            pstmt = conn.prepareStatement(sql);

            for(int i = 0;i < params.length;i++){
                pstmt.setObject(i+1,params[i]);
            }

            count = pstmt.executeUpdate();

        }catch(Exception e) {
            e.printStackTrace();
        }finally {
            //Release resources
            JdbcUtils.close(null,null,pstmt,conn);
        }
        return count;
    }

    /**
     *  @name        : public static <T> T query(String sql, MyHandler<T> handler, Object... params)throws Exception
     *	@description : Search in JdbcUtils
     *	@param		 : String sql, MyHandler<T> handler, Object... params
     *	@return		 : <T>
     *  @notice      : None
     */
    public static <T> T query(String sql, MyHandler<T> handler, Object... params)throws Exception {
        T result = null;
        ResultSet rs = null;
        Connection conn = null;
        PreparedStatement pstmt = null;

        try {
            conn = JdbcUtils.getconntion();
            pstmt = conn.prepareStatement(sql);
            if (params != null) {
                for (int i = 0; i < params.length; i++) {
                    // Set SQL parameters
                    pstmt.setObject(i + 1, params[i]);
                }
            }
            rs = pstmt.executeQuery();
            result = handler.handle(rs);

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            JdbcUtils.close(null,null,pstmt,conn);
        }
        return result;
    }

}
