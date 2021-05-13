import java.sql.*;

public class test {
    // MySQL 8.0 以下版本 - JDBC 驱动名及数据库 URL
//    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver";
//    static final String DB_URL = "jdbc:mysql://localhost:3306/assignment";

    // MySQL 8.0 以上版本 - JDBC 驱动名及数据库 URL
    static final String JDBC_DRIVER = "com.mysql.cj.jdbc.Driver";
    static final String DB_URL = "jdbc:mysql://localhost:3306/assignment?useSSL=false&allowPublicKeyRetrieval=true&serverTimezone=UTC";


    // 数据库的用户名与密码，需要根据自己的设置
    static final String USER = "root";
    static final String PASS = "123456";

    public static void main(String[] args) {
        Connection conn = null;
        Statement stmt = null;
        try {
            // 注册 JDBC 驱动
            Class.forName(JDBC_DRIVER);

            // 打开链接
            System.out.println("连接数据库...");
            conn = DriverManager.getConnection(DB_URL, USER, PASS);

            // 执行查询
            System.out.println(" 实例化Statement对象...");
            stmt = conn.createStatement();
            String sql;
            sql = "create table S" +
                    "(" +
                    "    sno    varchar(10) primary key," +
                    "    sname  varchar(20)," +
                    "    status varchar(5)," +
                    "    city   varchar(10)" +
                    ");";

            sql = "select * from S;";
            ResultSet rs = stmt.executeQuery(sql);
//            System.out.println(rs);
            // 展开结果集数据库
            while (rs.next()) {
                // 通过字段检索
                String sno = rs.getString("sno");
                String sname = rs.getString("sname");
                String status = rs.getString("status");
                String city = rs.getString("city");

                // 输出数据
                System.out.print("sno: " + sno);
                System.out.print(", sname: " + sname);
                System.out.print(", status: " + status);
                System.out.print(", city: " + city);
                System.out.print("\n");
            }
            // 完成后关闭
            rs.close();
            stmt.close();
            conn.close();
        } catch (SQLException se) {
            // 处理 JDBC 错误
            se.printStackTrace();
        } catch (Exception e) {
            // 处理 Class.forName 错误
            e.printStackTrace();
        } finally {
            // 关闭资源
            try {
                if (stmt != null) stmt.close();
            } catch (SQLException se2) {
            }// 什么都不做
            try {
                if (conn != null) conn.close();
            } catch (SQLException se) {
                se.printStackTrace();
            }
        }
        System.out.println("Goodbye!");
    }
}
