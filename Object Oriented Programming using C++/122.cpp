#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>

using namespace std;

template <typename T>
void swapTemp(T &a, T &b)
{
    T t;
    t = a;
    a = b;
    b = t;
}

int main()
{
    int a = 10, b = 20;
    swapTemp(a, b);
    cout << a << " " << b << endl;

    float c = 10.10, d = 20.20;
    swapTemp(c, d);
    cout << c << " " << d << endl;

    getch();
    return 0;
}