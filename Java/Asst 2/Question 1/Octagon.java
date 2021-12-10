public class Octagon extends Shape {
    int sides;
    double a;

    public Octagon(double a) {
        this.a = a;
    }

    int numberOfSides() {
        return sides;
    }

    double calculateArea() {
        return 2 * (1 + Math.sqrt(2)) * a * a;
    }    
}
