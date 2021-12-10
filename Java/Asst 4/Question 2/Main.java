public class Main {
    public static void main(String[] args) {
        ASCII thread1 = new ASCII();
        Length thread2 = new Length();

        thread1.start();
        thread2.start();
    }
}
