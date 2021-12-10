public class Triangle extends Shape {
    int sides;
    double a;
    double b;
    double c;

    public Triangle(double a, double b, double c) {
        this.sides = 3;
        this.a = a;
        this.b = b;
        this.c = c;
    }

    int numberOfSides() {
        return sides;
    }

    double calculateArea() {
        double s = (a + b + c) / 2;
        return Math.sqrt(s * (s - a) * (s - b) * (s - c));
    }
}
