import java.util.Scanner;

public class Main {
    public static void printDetails(Shape s) {
        System.out.println("The number of sides is " + s.numberOfSides());
        System.out.println("The area is " + s.calculateArea());
        System.out.println("-------------");
        System.out.println();
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        double a, b, c;
        Shape s;

        // For Triangle
        System.out.println("Enter the sides of a triangle:");
        a = sc.nextDouble();
        sc.nextLine();
        b = sc.nextDouble();
        sc.nextLine();
        c = sc.nextDouble();
        sc.nextLine();
        s = new Triangle(a, b, c);
        printDetails(s);

        // For Square
        System.out.println("Enter the side of a square:");
        a = sc.nextDouble();
        s = new Square(a);
        printDetails(s);

        // For Pentagon
        System.out.println("Enter the side and perpendicular of a pentagon:");
        a = sc.nextDouble();
        sc.nextLine();
        b = sc.nextDouble();
        s = new Pentagon(a, b);
        printDetails(s);

        // For Hexagon
        System.out.println("Enter the side of a hexagon:");
        a = sc.nextDouble();
        s = new Hexagon(a);
        printDetails(s);

        // For Octagon
        System.out.println("Enter the side of an octagon:");
        a = sc.nextDouble();
        s = new Octagon(a);
        printDetails(s);

        sc.close();
    }
}
