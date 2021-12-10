import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter the size of the array: ");
        int n = sc.nextInt();
        ArrayClass arr = new ArrayClass(n);

        arr.read();
        arr.sort();
        arr.display();
        sc.close();
    }
}
