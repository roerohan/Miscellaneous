import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        PriorityQueue<Patient> priorityQueue = new PriorityQueue<Patient>(10, new PriorityComparator());

        Scanner sc = new Scanner(System.in);

        int currentPatientId = 0;
        boolean exit = false;
        do {
            System.out.println();
            System.out.println("1. Enter Patient Details.");
            System.out.println("2. Show Patient Queue.");
            System.out.println("3. Exit.");

            System.out.print("Enter your choice: ");
            int num = sc.nextInt();
            sc.nextLine();

            System.out.println();
            switch (num) {
                case 1: {
                    int id = ++currentPatientId;

                    System.out.println("Enter the Patient Name:");
                    String name = sc.nextLine();

                    System.out.println("Enter the Emergency:");
                    System.out.println("Possible options: COVID-19, Dengue, Typhoid, Malaria, Common Cold");
                    String emergency = sc.nextLine();
                    int priority = PriorityCalculator.calculate(emergency);

                    priorityQueue.add(new Patient(id, name, priority, emergency));
                    break;
                }

                case 2: {
                    System.out.println("Timestamp\t\tPatient ID\tPatient Name\tPatient Priority\t Emergency");
                    Iterator<Patient> iterator = priorityQueue.iterator();

                    while (iterator.hasNext()) {
                        Patient patient = iterator.next();
                        System.out.println(
                                patient.getTimestamp() + "\t\t" + patient.getId() + "\t\t" + patient.getName() + "\t\t" + patient.getPriority() + "\t\t " + patient.getEmergency());
                    }
                    break;
                }

                case 3: {
                    exit = true;
                    break;
                }

                default: {
                    System.out.println("Invalid option, try again.");
                    break;
                }
            }
        } while (!exit);
        sc.close();
    }
}
