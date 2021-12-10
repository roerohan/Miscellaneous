import java.sql.*;

public class Main {
    static final String DB_URL = "jdbc:mysql://localhost/main";
    static final String USERNAME = "roerohan";
    static final String PASSWORD = "password";
    static final String QUERY = "SELECT id, name, email, registration_number FROM students;";

    public static void main(String args[]) {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");

            System.out.println("Connecting to SQL Database...");
            Connection conn = DriverManager.getConnection(DB_URL, USERNAME, PASSWORD);

            Statement stmt = conn.createStatement();
            System.out.println("Executing query: " + QUERY + "\n");

            ResultSet rs = stmt.executeQuery(QUERY);
            while (rs.next()) {
                System.out.println("ID: " + rs.getInt("id"));
                System.out.println("Name: " + rs.getString("name"));
                System.out.println("Email: " + rs.getString("email"));
                System.out.println("Registration Number: " + rs.getString("registration_number"));
                System.out.println();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
