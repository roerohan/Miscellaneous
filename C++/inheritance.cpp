#include <iostream>
using namespace std;

class Square
{
public:
    int side;

    Square(int s)
    {
        side = s;
    }
};

class Cube : public Square
{
public:
    int getSurfaceArea()
    {
        return side * side * 6;
    }

    int getVolume()
    {
        return side * side * side;
    }

    Cube(int side) : Square(side) {}
};

int main()
{
    int side;

    cin >> side;
    Cube cube(side);

    cout << "Surface area " << cube.getSurfaceArea() << endl;
    cout << "Volume " << cube.getVolume() << endl;
}