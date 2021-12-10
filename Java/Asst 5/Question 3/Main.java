import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of food objects to be stored:");
        int n = sc.nextInt();
        sc.nextLine();

        try {
            FileOutputStream f = new FileOutputStream(new File("foodObjects.txt"));
			ObjectOutputStream o = new ObjectOutputStream(f);

            for(int i = 0; i < n; i++) {
                System.out.println("Enter the name:");
                String name = sc.nextLine();

                System.out.println("Enter the type:");
                String type = sc.nextLine();

                System.out.println("Enter the calories:");
                double calories = sc.nextDouble();
                sc.nextLine();

                System.out.println("Enter the price:");
                double price = sc.nextDouble();
                sc.nextLine();

                Food food = new Food(name, type, calories, price);
                o.writeObject(food);
            }
            o.close();
            f.close();

            System.out.println("\nStored objects in foodObjects.txt\n");
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        } catch (Exception e) {
            e.printStackTrace();
        }

        try {
            System.out.println("Displaying food with greater than 1500 calories\n");
            FileInputStream fi = new FileInputStream(new File("foodObjects.txt"));
			ObjectInputStream oi = new ObjectInputStream(fi);

            for (int i = 0; i < n; i++) {
                Food food = (Food) oi.readObject();
                if (food.getCalories() > 1500) {
                    System.out.println(food.toString());
                    System.out.println();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
