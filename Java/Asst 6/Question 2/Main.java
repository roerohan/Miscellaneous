import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        HashMap<String, Double> students = new HashMap<>();

        int n;

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of students: ");
        n = sc.nextInt();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter regno for student " + (i + 1) + ": ");
            String regNo = sc.next();

            System.out.println("Enter CGPA for student " + (i + 1) + ": ");
            double cgpa = sc.nextDouble();

            students.put(regNo, cgpa);
        }

        System.out.println("Enter regno to search: ");
        String regNo = sc.next();

        if (students.containsKey(regNo)) {
            System.out.println("CGPA of " + regNo + " is " + students.get(regNo));
        } else {
            System.out.println("CGPA of " + regNo + " is not found");
        }

        System.out.println("Enter CGPA to search for: ");
        double cgpa = sc.nextDouble();

        for (String key : students.keySet()) {
            if (students.get(key) == cgpa) {
                System.out.println("Regno of student with CGPA " + cgpa + " is " + key);
            }
        }

        sc.close();
    }
}
