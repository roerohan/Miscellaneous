package P1;
import java.util.*;

public class Strings {
    protected String strings[];

    public Strings(int length) {
        strings = new String[length];
    }

    public String[] getStrings() {
        return strings;
    }

    public String get(int index) {
        return strings[index];
    }

    public void inputStrings() {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < strings.length; i++) {
            System.out.println("Enter string " + (i + 1) + ": ");
            strings[i] = sc.nextLine();
        }
        sc.close();
    }
}
