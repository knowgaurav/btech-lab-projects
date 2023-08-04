#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

/*template <class T>
void compareInput(T x, T y)
{
    T a = x;
    x = y;
    y = a;

    cout << "After swapping:" << x << ", " << y << endl;
}*/

template <typename T, typename R>
class test
{
    T x[10];
    R y;

public:
    void input()
    {
        cout << "Enter uperbound: ";
        cin >> y;
        cout << endl
             << "Enter name: ";
        for (int i = 0; i < y; i++)
        {
            cin >> x[i];
        }
    }
    void print()
    {
        cout << endl
             << "Name is: ";
        for (int i = 0; i < y; i++)
        {
            cout << x[i];
        }
    }
};

int main()
{
    test<char, int> t1;
    t1.input();
    t1.print();

    cout << endl;

    getch();
    return 0;
}