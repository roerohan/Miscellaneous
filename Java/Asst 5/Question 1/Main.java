import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            System.out.println("Enter the number of students:");

            Scanner sc = new Scanner(System.in);

            int n = sc.nextInt();
            sc.nextLine();

            File fout = new File("registrationNumbers.txt");
            FileOutputStream fos = new FileOutputStream(fout);

            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(fos));

            for (int i = 0; i < n; i++) {
                System.out.print("Enter the registration number of student " + (i + 1) + ": ");
                String regNo = sc.nextLine();

                bw.write(regNo);
                bw.newLine();
            }

            bw.close();

            File upperCase = new File("uppercase.txt");
            FileOutputStream ufos = new FileOutputStream(upperCase);

            BufferedWriter ubw = new BufferedWriter(new OutputStreamWriter(ufos));

            try (BufferedReader br = new BufferedReader(new FileReader(new File("registrationNumbers.txt")))) {
                String line;
                while ((line = br.readLine()) != null) {
                    ubw.write(line.toUpperCase());
                    ubw.newLine();
                }
            }

            ubw.close();
            sc.close();

        } catch (Exception e) {
            System.out.println(e);
        }

    }
}
