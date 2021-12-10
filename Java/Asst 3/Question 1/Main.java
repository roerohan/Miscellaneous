import java.util.*;

class Employee {
    private String name;

    private int yearsOfExperience;

    private double performanceRatings[];

    private double salary;

    public Employee(String name, int yearsOfExperience, double salary) {
        this.name = name;
        this.yearsOfExperience = yearsOfExperience;
        this.performanceRatings = new double[yearsOfExperience];
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public int getYearsOfExperience() {
        return yearsOfExperience;
    }

    public double getSalary() {
        return salary;
    }

    public void inputPerformanceRating(Scanner sc) {
        for (int i = 0; i < yearsOfExperience; i++) {
            System.out.println("Enter performance rating for year " + (i + 1) + ": ");
            double performanceRating = sc.nextDouble();
            performanceRatings[i] = performanceRating;
        }
    }

    public double avgPerformanceIndex() {
        double sum = 0;
        for (int j = 0; j < yearsOfExperience; j++) {
            sum += performanceRatings[j];
        }
        return (sum / yearsOfExperience);
    }
}

public class Main {
    public static void displayEmployeeDetails(ArrayList<Employee> employees) {
        System.out.println();

        for (Employee employee : employees) {
            System.out.println("Name: " + employee.getName());
            System.out.println("Salary: " + employee.getSalary());
            System.out.println("Years of experience: " + employee.getYearsOfExperience());
            try {
                System.out.println("Average performance rating: " + employee.avgPerformanceIndex());
            } catch (ArithmeticException e) {
                System.out.println("Average performance rating: 0");
            }
            System.out.println();
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Employee> employees = new ArrayList<Employee>();

        System.out.println("Enter the number of employees.");
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            System.out.println("Enter the name of the employee.");
            String name = sc.nextLine();

            System.out.println("Enter the years of experience of the employee.");
            int yearsOfExperience = sc.nextInt();
            sc.nextLine();

            System.out.println("Enter the salary.");
            double salary = sc.nextDouble();
            sc.nextLine();

            Employee emp = new Employee(name, yearsOfExperience, salary);
            System.out.println("Enter the performance ratings of the employee.");

            emp.inputPerformanceRating(sc);
            employees.add(emp);
            sc.nextLine();
        }

        displayEmployeeDetails(employees);

        sc.close();
    }
}
