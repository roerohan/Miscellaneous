public class Main {
    public static void main(String args[]) {
        try {
            Artifacts artifacts = new Artifacts();
            Fibonacci thread1 = new Fibonacci(artifacts);
            PrimeComposite thread2 = new PrimeComposite(artifacts);
            Display thread3 = new Display(artifacts);
            thread1.start();
            thread2.start();
            thread2.join();
            thread3.start();
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
