import java.util.*;
 
public class Main {
   public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       System.out.println("Enter a string:");
       String s = sc.nextLine();
       Prefix thread1 = new Prefix(s);
       Suffix thread2 = new Suffix(s);
       thread1.start();
       thread2.start();
       sc.close();
 
       System.out.println("The Prefixes of " + s + ":");
       displayStrings(thread1.prefixes);
       System.out.println();
       System.out.println("The Suffixes of " + s + ":");
       displayStrings(thread2.suffixes);
   };
 
   public static void displayStrings(ArrayList<String> list) {
       for (String s : list) {
           System.out.println(s);
       }
   }
}
