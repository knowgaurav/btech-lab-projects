#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std;

class student
{
    string name;

public:
    static int id;
    student()
    {
        id++;
    }
    void setData(string n)
    {
        name = n;
    }
    void display()
    {
        cout << "The name of the student is: " << name << endl;
    }
};

int student::id = 0;

int main()
{
    student S1;
    S1.setData("The Rock");
    cout << "The ID of the student is: " << student::id << endl;
    S1.display();
    student S2;
    S2.setData("Brock Lesnar");
    cout << "The ID of the student is: " << student::id << endl;
    S2.display();
    getch();
    return 1;
}