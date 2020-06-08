#include <iostream>
using namespace std;

class Complex
{
private:
    int real, imaginary;

public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }

    Complex operator+(Complex const &obj)
    {
        Complex sum;
        sum.real = real + obj.real;
        sum.imaginary = imaginary + obj.imaginary;

        return sum;
    }

    Complex operator-(Complex const &obj)
    {
        Complex diff;
        diff.real = real - obj.real;
        diff.imaginary = imaginary - obj.imaginary;

        return diff;
    }

    void print()
    {
        if (imaginary < 0)
        {
            cout << real << "-i" << -imaginary << endl;
        }
        else
        {
            cout << real << "+i" << imaginary << endl;
        }
    }
};

int main()
{
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    Complex obj1(r1, c1), obj2(r2, c2);
    Complex sum = obj1 + obj2;
    Complex diff = obj1 - obj2;

    sum.print();
    diff.print();
}