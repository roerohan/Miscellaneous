public class Pentagon extends Shape {
    int sides;
    double a;
    double p;

    public Pentagon(double a, double p) {
        this.sides = 5;
        this.a = a;
        this.p = p;
    }

    int numberOfSides() {
        return sides;
    }

    double calculateArea() {
        return (p * a) / 2;
    }
}
