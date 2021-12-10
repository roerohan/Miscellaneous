public class PrimeComposite extends Thread {
    Artifacts artifacts;

    PrimeComposite(Artifacts artifacts) {
        this.artifacts = artifacts;
    }

    public boolean isPrime(int n) {
        int i, m = 0, flag = 0;
        m = n / 2;
        if (n == 0 || n == 1) {
            return false;
        } else {
            for (i = 2; i <= m; i++) {
                if (n % i == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                return true;
            } else {
                return false;
            }
        }
    }

    public void run() {
        // Wait for shared LinkedList to start getting populated.
        while (artifacts.getLLLength() == 0)
            ;

        // Get the number of items in the LinkedList.
        int count = artifacts.getLLLength();

        for (int i = 0; i < count; i++) {
            // Wait for the list item to get populated, since threads are running in
            // parallel.
            while (artifacts.getLLItem(i) == Integer.MIN_VALUE)
                ;

            int item = artifacts.getLLItem(i);

            if (isPrime(item)) {
                artifacts.addPrime(item);
            } else if (item == 0 || item == 1) {
                // Do nothing, since 0 and 1 are neither prime nor composite
            } else {
                artifacts.addComposite(item);
            }
        }
    }
}
