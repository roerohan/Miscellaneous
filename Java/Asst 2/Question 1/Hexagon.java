public class Hexagon extends Shape {
    int sides;
    double a;

    public Hexagon(double a) {
        this.sides = 6;
        this.a = a;
    }

    int numberOfSides() {
        return sides;
    }

    double calculateArea() {
        return (3 * Math.sqrt(3) * a * a) / 2;
    }
}
