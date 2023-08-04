#include <iostream>
#include <conio.h>

using namespace std;

class Student
{
    int marks;

public:
    Student(int m)
    {
        this->marks = m;
    }

    void operator++()
    {
        marks += 1;
    }

    void operator--()
    {
        marks -= 1;
    }

    void display()
    {
        cout << "Marks are: " << marks << endl;
    }
};

int main()
{
    Student Gaurav(100);
    ++Gaurav;
    Gaurav.display();
    --Gaurav;
    Gaurav.display();

    getch();
    return 0;
}