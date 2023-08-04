#include<iostream>
#include<conio.h>

using namespace std;

class A {
    int a;
    string str = "Gaurav";
public:
    A() {
        a = 20;
    }
    friend class B;
};

class B {
    int b;
public:
    void showA(A x) {
        cout << "Private member data of Class A is: "<<x.a <<endl;
        cout << "Private member data of Class A is: "<<x.str <<endl;
    }
};

int main() {
    A class1;
    B class2;
    class2.showA(class1);

    getch();
    return 0;
}