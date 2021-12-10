import java.util.ArrayList;

public class Display extends Thread {
    Artifacts artifacts;

    Display(Artifacts artifacts) {
        this.artifacts = artifacts;
    }

    public void run() {
        try {
            ArrayList<Integer> prime = artifacts.getPrime();
            ArrayList<Integer> composite = artifacts.getComposite();

            if (prime.size() == 0) {
                throw new Exception("Empty list exception");
            }

            System.out.println("Primes:");
            for (int p : prime) {
                System.out.println(p);
            }

            System.out.println("Composites:");
            for (int c : composite) {
                System.out.println(c);
            }
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
