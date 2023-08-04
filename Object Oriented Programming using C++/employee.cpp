#include <iostream>
#include <conio.h>

using namespace std;

class employee
{
protected:
    int id;
    string name;
    float salary;

public:
    employee()
    {
        int i;
        i = 9;
    }
    void empInfo(int i, string n, float s)
    {
        id = i;
        name = n;
        salary = s;
    }

    void empDisplay()
    {
        cout << "Employee: " << name << endl;
        cout << " with ID: " << id << endl;
        cout << " has salary " << salary << endl;
    }
};

class emp1 : public employee
{
};

int main()
{
    employee e1, e2;
    e1.empInfo(1, "Stark", 100000);
    e2.empInfo(2, "Wayne", 100);
    e1.empDisplay();
    e2.empDisplay();

    emp1 p1;
    p1.empInfo(3, "Gaurav", 100000);
    p1.empDisplay();

    getch();
    return 0;
}