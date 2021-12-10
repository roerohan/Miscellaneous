import java.util.Comparator;

public class PriorityComparator implements Comparator<Patient> {
    @Override
    public int compare(Patient p1, Patient p2) {
        if (p1.getPriority() < p2.getPriority()) {
            return 1;
        }

        if (p2.getPriority() < p1.getPriority()) {
            return -1;
        }

        if (p1.getId() < p2.getId()) {
            return -1;
        }

        if (p2.getId() < p1.getId()) {
            return 1;
        }

        return 0;
    }
}
