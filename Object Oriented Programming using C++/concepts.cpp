#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

#define STRINGIFY(x) #x

int main()
{

    /*int i = 10;
    int &j = i;

    c<< &i << endl;
    c<< &j << endl;

    int *k = new int;
    //*k = 10;
    c<< k << endl;*/

    cout << STRINGIFY(word);
    cout << STRINGIFY(word);
    //char *c = new char[];
    //c = "Hello";
    //c << *c <<endl;

    getch();
    return 0;
}