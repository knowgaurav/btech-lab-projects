#include <iostream>
#include <conio.h>

using namespace std;

class shape
{
public:
    int l, b;
    void getData(int len, int bre)
    {
        l = len;
        b = bre;
    }
};

class square : public shape
{
public:
    void display()
    {
        cout << "Area of square is: " << l * l << " Perimeter is: " << 4 * l;
    }
};

class rectangle : public shape
{
public:
    void display()
    {
        cout << "Area of rectangle is: " << l * b << " Perimeter is: " << 2 * (l + b);
    }
};

int main()
{
    square s1;
    rectangle r1;
    s1.getData(1, 1);
    s1.display();
    r1.getData(2, 3);
    r1.display();
    return 0;
}
