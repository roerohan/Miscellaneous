public class PriorityCalculator {
    public static int calculate(String emergency) {
        if (emergency.equalsIgnoreCase("COVID-19")) {
            return 5;
        }

        if (emergency.equalsIgnoreCase("Dengue") || emergency.equalsIgnoreCase("Typhoid")) {
            return 4;
        }

        if (emergency.equalsIgnoreCase("Malaria")) {
            return 3;
        }

        if (emergency.equalsIgnoreCase("Common Cold")) {
            return 2;
        }

        return 1;
    }
}
