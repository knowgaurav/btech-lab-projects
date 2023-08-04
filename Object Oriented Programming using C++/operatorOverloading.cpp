#include <iostream>
#include <conio.h>

using namespace std;

class test
{
    int real;
    int complex;

public:
    test(int x = 0, int y = 0)
    {
        real = x;
        complex = y;
    }

    friend void operator++(test &t);
    friend void operator--(test &t);
    friend test operator+(const test &t1, const test &t2);
    friend test operator-(const test &t1, const test &t2);

    void display()
    {
        cout << "Expression is: " << real << " + " << complex << "i";
    }
};

void operator++(test &t)
{
    t.real += 1;
    t.complex += 1;
}
void operator--(test &t)
{
    t.real--;
    t.complex--;
}

test operator+(const test &t1, const test &t2)
{
    test t;
    t.real = t1.real + t2.real;
    t.complex = t2.complex + t1.complex;
    return t;
}
test operator-(const test &t1, const test &t2)
{
    test t;
    t.real = t1.real - t2.real;
    t.complex = t1.complex - t2.complex;
    return t;
}

int main()
{
    test T(10, 20), T1(5, 8), T2(8, 2), T3;
    printf("--- C++ Operator Overloading using Friend Demonstration --- \n\n");
    cout << endl;

    ++T;
    cout << "Encrement Operator Overloading Result: ";
    T.display();

    cout << endl;
    cout << endl;
    cout << "Decrement Operator Overloading Result: ";
    --T;
    T.display();

    cout << endl;
    cout << endl;
    cout << "Addition Operator Overloading Result: ";
    T3 = operator+(T1, T2);
    T3.display();

    cout << endl;
    cout << endl;
    cout << "Subtraction Operator Overloading Result: ";
    T3 = operator-(T1, T2);
    T3.display();

    getch();
    return 0;
}