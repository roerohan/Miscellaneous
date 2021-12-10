public class ASCII extends Thread {
    public static void display() {
        for (char c = 'A'; c <= 'Z'; c++) {
            System.out.println("The ASCII value of " + c + " is " + (int) c + "\n");
        }
    }

    public void run() {
        display();
    }
}
