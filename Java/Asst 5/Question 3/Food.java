import java.io.Serializable;

public class Food implements Serializable {
    String name;
    
    String type;

    double calories;

    double price;

    Food(String name, String type, double calories, double price) {
        this.name = name;
        this.type = type;
        this.calories = calories;
        this.price = price;
    }

    @Override
    public String toString() {
        return "Name: " + name + "\nType: " + type + "\nCalories: " + calories + "\nPrice: " + price;
    }

    public String getName() {
        return name;
    }

    public String getType() {
        return type;
    }

    public double getCalories() {
        return calories;
    }

    public double getPrice() {
        return price;
    }
}
