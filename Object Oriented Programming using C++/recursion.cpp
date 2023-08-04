#include <iostream>
#include <conio.h>

using namespace std;

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }

    int S1 = fib(n - 1);
    int S2 = fib(n - 2);

    return S1 + S2;
}

int main()
{
    cout << fib(0) << endl;

    getch();
    return 0;
}