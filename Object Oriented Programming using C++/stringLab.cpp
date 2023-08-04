#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>

using namespace std;

//Using String Object
/*int main()
{
    string str1, str2, str3;
    cout << "Enter the contents of string 1" << endl;
    getline(cin, str1);
    cout << "\nEnter the contents of string 2" << endl;
    getline(cin, str2);
    str3 = str1 + " " + str2;
    cout << "\nConcatinated string: " << str3 << endl;

    cout << "\nString Comparison: " << endl;
    if (str1 == str2)
        cout << "Strings are equal!";
    else
        cout << "Strings are not equal!";

    getch();
    return 0;
}*/

int main()
{
    /*int value, i;
    int ch;

    cout << "\nConcatinated string: " << str3 << endl;
    strcat(str1, str2);
    for (int i = 0; str1[i] != '\0'; i++)
    {
        cout << str1[i];
    }*/

    /*string name = "Gaurav Singh Gaurav";
    string strMiddle;
    int i;

    for (i = 0; name[i] != ' '; i++)
        ;
    strMiddle = name.substr(i + 1, 3);
    cout << strMiddle;*/

    int value, i;
    int ch;

    while (1)
    {
        char str1[100];
        char str2[100];
        printf("Enter a command(1 or 9 to quit): \n");
        printf("   1. Enter new command\n");
        printf("   9. To Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            cout << "\nEnter the contents of string 1: ";
            cin.ignore();
            cin.getline(str1, 20);
            //cin >> str1;
            cout << "\nEnter the contents of string 2: ";
            //cin.ignore();
            cin.getline(str2, 20);
            //cin >> str2;
            cout << "\nthe contents of string 1: ";
            //cin.ignore();
            cout << str1;
            //cin >> str1;
            cout << "\nthe contents of string 2: ";
            //cin.ignore();
            cout << str2;
            cout << "\nString Compare: " << endl;
            i = strcmp(str1, str2);
            cout << i << endl;
            if (i == 0)
            {
                cout << "Strings are equal!" << endl;
            }
            else if (i < 0)
            {
                cout << "String 1 is smaller" << endl;
            }
            else
            {
                cout << "String 2 is smaller" << endl;
            }
            break;
        case 9:
            exit(1);
        default:
            printf("Invalid Input \n\n");
        }

        printf("\n\n");
    }
    getch();
    return 0;
}

template <typename T>
T cube(T x)
{
    return x * x * x;
}

int main()
{
    T<int> x = 10;
    cout << x << endl;

    getch();
    return 0;
}
