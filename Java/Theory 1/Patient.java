import java.text.SimpleDateFormat;
import java.util.Date;

public class Patient {
    private int id;
    private String name;
    private int priority;
    private String emergency;
    private String timestamp;

    public Patient(int id, String name, int priority, String emergency) {
        this.id = id;
        this.name = name;
        this.priority = priority;
        this.emergency = emergency;
        this.timestamp = new SimpleDateFormat("dd-MM-yyyy HH.mm.ss").format(new Date());
    }

    public int getPriority() {
        return priority;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getEmergency() {
        return emergency;
    }

    public String getTimestamp() {
        return timestamp;
    }
}
