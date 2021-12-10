import java.util.*;

public class Length extends Thread {
    public static void calculate() {
        System.out.println("Enter a string");
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        System.out.println("The length of the string " + str + " is " + str.length());
        sc.close();
    }

    public void run() {
        calculate();
    }
}
