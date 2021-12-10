import java.util.HashSet;

public class Main {
    public static void main(String args[]) {
        HashSet<Integer> hs1 = new HashSet<Integer>();
        HashSet<Integer> hs2 = new HashSet<Integer>();

        hs1.add(1);
        hs1.add(2);
        hs1.add(4);
        hs1.add(8);
        hs1.add(12);

        hs2.add(1);
        hs2.add(3);
        hs2.add(6);
        hs2.add(12);
        hs2.add(18);

        HashSet<Integer> hs1UnionHs2 = new HashSet<Integer>(hs1);
        hs1UnionHs2.addAll(hs2);

        HashSet<Integer> hs1IntersectionHs2 = new HashSet<Integer>(hs1);
        hs1IntersectionHs2.retainAll(hs2);

        HashSet<Integer> hs1DifferenceHs2 = new HashSet<Integer>(hs1);
        hs1DifferenceHs2.removeAll(hs2);

        System.out.println("HashSet hs1: " + hs1);
        System.out.println("HashSet hs2: " + hs2);
        System.out.println("\nPerforming Set Operations:");
        System.out.println("Union: " + hs1UnionHs2);
        System.out.println("Intersection: " + hs1IntersectionHs2);
        System.out.println("Difference: " + hs1DifferenceHs2);
    }
}
