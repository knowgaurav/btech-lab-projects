#include <iostream>

using namespace std;

class area
{
    int len, bre;

public:
    area()
    {
        len = 0;
        bre = 0;
        cout << len;
        cout << bre;
    }
    area(int l, int b)
    {
        len = l;
        bre = b;
        cout << l;
        cout << b;
    }
};

int main()
{
    area a1;
    area(10, 20);
}