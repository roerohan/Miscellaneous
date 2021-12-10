import java.util.ArrayList;
import java.util.LinkedList;

public class Artifacts {
    private int llLength;
    private LinkedList<Integer> ll;
    private ArrayList<Integer> prime;
    private ArrayList<Integer> composite;

    public Artifacts() {
        ll = new LinkedList<Integer>();
        prime = new ArrayList<Integer>();
        composite = new ArrayList<Integer>();
    }

    public int getLLLength() {
        return llLength;
    }

    public void setLLLength(int llLength) {
        this.llLength = llLength;
    }

    public int getLLItem(int index) {
        if (index < ll.size()) {
            return ll.get(index);
        }

        return Integer.MIN_VALUE;
    }

    synchronized void addItemToLL(int e) {
        ll.addLast(e);
    }
    
    public ArrayList<Integer> getPrime() {
        return prime;
    }

    synchronized void addPrime(int e) {
        prime.add(e);
    }

    public ArrayList<Integer> getComposite() {
        return composite;
    }

    synchronized void addComposite(int e) {
        composite.add(e);
    }
}