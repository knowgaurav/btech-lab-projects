#include <iostream>
#include <conio.h>

using namespace std;

class calculator {
    int num1, num2;
public:
    void getData();
    void sum();
    void diff();
    void mult();
    void divide();
};

inline void calculator::getData() {
    cout << "Enter the first number" << endl;
    cin >> num1;
    cout << "Enter the second number" << endl;
    cin >> num2;
}

inline void calculator::sum() {
    cout<< "The sum of the given numbers is: " << num1+num2 <<endl;
}

inline void calculator::diff() {
    cout<< "The difference of the given numbers is: " << num1-num2 <<endl;
}

inline void calculator::mult() {
    cout<< "The product of the given numbers is: " << num1*num2 <<endl;
}

inline void calculator::divide() {
    cout<< "The dision of the given numbers is : " << num1/num2 <<endl;
}

int main() {
    calculator c;
    int opt = 0;
    c.getData();
    cout << "Which operation do you wish to perform: "<<endl;
    cin  >> opt;
    switch (opt)
    {
    case 1:
        c.sum();
        break;

    case 2:
        c.diff();
        break;

    case 3:
        c.mult();
        break;

    case 4:
        c.divide();
        break;

    case 5:
        exit(1);
    default:
        printf("Invalid Input \n\n");
    }

    getch();
    return 0;
}
