import java.util.Scanner;

public class Main {
    @FunctionalInterface
    public interface Sum_of_Series {
        double sine(double x, int n);
    }

    public static int factorial(int n) {
        int f = 1;
        for (int i = 1; i <= n; i++) {
            f *= i;
        }

        return f;
    }

    public static void main(String args[]) {
        Sum_of_Series lambda = (double x, int n) -> {
            double sum = 0;
            for (int i = 1; i <= n; i++) {
                int m = (2 * i) - 1;
                
                sum += (Math.pow(-1, (i + 1)) * Math.pow(x, m)) / factorial(m);
            }
            return sum;
        };

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of x:");
        double x = sc.nextDouble();
        System.out.println("Enter the value of n:");
        int n = sc.nextInt();
        System.out.println(lambda.sine(x, n));

        sc.close();
    }
}