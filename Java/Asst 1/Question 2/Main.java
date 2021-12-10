import java.io.*;
import java.lang.*;
import java.util.*;

class Student {
    String name;
    String regNo;
    int[] marks;
    float avg;
    static Scanner sc = new Scanner(System.in);

    void takeInput(Scanner sc) {
        System.out.println("Enter the name of the student");
        this.name = sc.nextLine();
        System.out.println("Enter the regno of the student");
        this.regNo = sc.nextLine();
        System.out.println("Enter the marks of the student in 6 courses:");
        this.marks = new int[6];

        float total = 0;
        for (int i = 0; i < 6; i++) {
            this.marks[i] = sc.nextInt();
            sc.nextLine();
            total += this.marks[i];
        }

        this.avg = total / 6;
    }

    void displayDetails() {
        System.out.println("Name:" + name);
        System.out.println("Reg No: " + regNo);
        System.out.print("Marks in courses: ");
        for (int i = 0; i < 6; i++) {
            System.out.print(this.marks[i] + " ");
        }
        System.out.println();
        System.out.println("Average Marks: " + this.avg);
    }
}

public class Main {
    public static void main(String[] args) {
        ArrayList<Student> studs = new ArrayList<Student>();

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the no of students:");

        int n = sc.nextInt();
        sc.nextLine();

        System.out.println("Enter details of " + n + " students:");
        System.out.println();

        for (int i = 0; i < n; i++) {
            Student s = new Student();
            s.takeInput(sc);
            studs.add(s);
            System.out.println();
        }

        ArrayList<Student> slowLearners = new ArrayList<Student>();
        ArrayList<Student> normalLearners = new ArrayList<Student>();
        ArrayList<Student> fastLearners = new ArrayList<Student>();

        for (int i = 0; i < n; i++) {
            Student curr = studs.get(i);
            if (curr.avg < 40) {
                slowLearners.add(curr);
            } else if (curr.avg < 90) {
                normalLearners.add(curr);
            } else {
                fastLearners.add(curr);
            }
        }

        System.out.println("Slow Learners:");
        System.out.println();
        for (int i = 0; i < slowLearners.size(); i++) {
            slowLearners.get(i).displayDetails();
            System.out.println();
        }
        System.out.println();

        System.out.println("Normal Learners:");
        System.out.println();
        for (int i = 0; i < normalLearners.size(); i++) {
            normalLearners.get(i).displayDetails();
            System.out.println();

        }
        System.out.println();

        System.out.println("Fast Learners:");
        System.out.println();
        for (int i = 0; i < fastLearners.size(); i++) {
            fastLearners.get(i).displayDetails();
            System.out.println();
        }
        System.out.println();

        sc.close();
    }
}
