import java.util.LinkedList;

public class Fibonacci extends Thread {
    Artifacts artifacts;

    Fibonacci(Artifacts artifacts) {
        this.artifacts = artifacts;
    }

    public void run() {
        int n1 = 0;
        int n2 = 1;
        int n3;

        LinkedList<Integer> arr = new LinkedList<Integer>();

        arr.addLast(n1);
        arr.addLast(n2);

        while (true) {
            n3 = n1 + n2;
            if (n3 > 100) {
                break;
            }
            arr.addLast(n3);
            n1 = n2;
            n2 = n3;
        }

        artifacts.setLLLength(arr.size());

        System.out.println("Linked List of Fibonacci till 100:");
        for (int item : arr) {
            System.out.println(item);
            artifacts.addItemToLL(item);
        }

        System.out.println();
    }
}
