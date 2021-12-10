package P1.P2;

import java.util.*;

public class Concatenate extends P1.Strings {
    public Concatenate(int length) {
        super(length);
    }

    public void concatenateStringsOfSameLength() {
        HashMap<Integer, String> map = new HashMap<>();
        for (int i = 0; i < strings.length; i++) {
            int length = strings[i].length();
            if (map.containsKey(length)) {
                map.put(length, map.get(length) + strings[i]);
            } else {
                map.put(length, strings[i]);
            }
        }

        Iterator it = map.entrySet().iterator();
  
        System.out.println("After concatenating strings of same length, the elements in the array are");
        while (it.hasNext()) {
            Map.Entry mapElement = (Map.Entry)it.next();
            System.out.println(mapElement.getValue());
        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the array of strings: ");
        int length = sc.nextInt();
        sc.nextLine();

        Concatenate concatenate = new Concatenate(length);
        concatenate.inputStrings();
        concatenate.concatenateStringsOfSameLength();
    }
}
