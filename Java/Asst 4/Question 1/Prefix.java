import java.util.ArrayList;
 
public class Prefix extends Thread {
   ArrayList<String> prefixes;
   String s;
 
   public Prefix(String inp) {
       prefixes = new ArrayList<String>();
       s = inp;
   }
 
   public void calculate(String k) {
       if (k.length() == 0) {
           return;
       }
       prefixes.add(k);
       calculate(k.substring(0, k.length() - 1));
   }
 
   public void run() {
       calculate(s);
   }
}
