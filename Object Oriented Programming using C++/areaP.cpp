
#include <iostream>
#include <conio.h>
using namespace std;
class Square
{
public:
    int side, sarea, sperimeter;
    Square()
    {
        side = 0;
    }
    void getsData(int s)
    {
        side = s;
        sarea = side * side;
        sperimeter = 4 * side;
    }
};
class Rectangle
{
public:
    int l, b, rarea = 0, rperimeter = 0;
    Rectangle()
    {
        l = 0;
        b = 0;
    }
    void getrData(int len, int bre)
    {
        l = len;
        b = bre;
        rarea = l * b;
        rperimeter = 2 * (l + b);
    }
};
class C : public Square, public Rectangle //C is derived from class Square and class Rectangle
{
public:
    void dataDisplay()
    {
        cout << "Square: "
             << "Area = " << sarea << ", Perimeter = " << sperimeter << "\n";
        cout << "Rectangle: "
             << "Area = " << rarea << ", Perimeter = " << rperimeter << "\n";
    }
};

int main()
{
    C c1;

    c1.getsData(1);
    c1.getrData(2, 4);
    c1.dataDisplay();

    getch();
    return 0;
}
