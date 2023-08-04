/*#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int n, fact = 1;

    cout << "Enter the integer: ";
    try
    {
        cin >> n;
        if (n >= 8)
        {
            throw("Error, cannot be more than 7!");
        }
        for (int i = 1; i <= n; ++i)
        {
            fact *= i;
        }
        cout << "Factorial is" << fact << endl;
    }
    catch (const char *er)
    {
        cout << er << endl;
    }
    getch();
    return 0;
}*/

/*#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter two numbers: " << endl;
    cin >> a >> b;
    try
    {
        if (b == 0)
            throw();

        cout << a / b;
    }
    catch (const char *er)
    {
        cout << er << endl;
    }

    getch();
    return 0;
}*/

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int a = 1;
    char b = 'g';
    float c = 20.20;
    try
    {
        try
        {
            try
            {
                throw(a);
            }
            catch (int e)
            {
                cout << "Integer is: " << e << endl;
            }
            throw b;
        }
        catch (char ch)
        {
            cout << "Character is: " << ch << endl;
        }
        throw c;
    }
    catch (...)
    {
        cout << "Default error!" << endl;
    }

    getch();
    return 0;
}