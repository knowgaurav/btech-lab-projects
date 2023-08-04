#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

class grandBear
{
    int j;

public:
    grandBear()
    {
        cout << "First Class";
    }
};

class papaBear : public grandBear
{
    int j;

public:
    papaBear()
    {
        cout << "\nSecond Class";
    }
};

class Bear : public papaBear
{
    int k = 10;

public:
    Bear()
    {
        k = 0;
    }
    Bear(int k)
    {
        k = k;
        cout << "\nThird Class with parametrized: " << k;
    }
};

int main()
{
    Bear B1;
    //Bear(10);
    getch();
}