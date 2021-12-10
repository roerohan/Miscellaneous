public class Square extends Shape {
    int sides;
    double s;

    public Square(double s) {
        this.sides = 4;
        this.s = s;
    }

    int numberOfSides() {
        return sides;
    }

    double calculateArea() {
        return s * s;
    }    
}
