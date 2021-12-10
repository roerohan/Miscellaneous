import java.util.ArrayList;
 
public class Suffix extends Thread {
   ArrayList<String> suffixes;
   String s;
 
   public Suffix(String inp) {
       suffixes = new ArrayList<String>();
       s = inp;
   }
 
   public void calculate(String k) {
       if (k.length() == 0) {
           return;
       }
       suffixes.add(k);
       calculate(k.substring(1, k.length()));
   }
 
   public void run() {
       calculate(s);
   }
}
