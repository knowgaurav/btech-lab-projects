#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

template <class X>
class stack
{
    X *arr;
    int top;
    int capacity;

public:
    stack(int size)
    {
        arr = new X[size];
        capacity = size;
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == capacity - 1;
    }
    void push(X x)
    {
        if (isFull())
        {
            cout << "Stack is full, OverFlow\n";
            exit(1);
        }

        cout << "Inserting " << x << endl;
        arr[++top] = x;
    }

    X pop()
    {

        if (isEmpty())
        {
            cout << "Stack is empty, UnderFlow\n";
            exit(1);
        }

        cout << "Removing " << peek() << endl;

        return arr[top--];
    }

    X peek()
    {
        if (!isEmpty())
            return arr[top];
        else
            exit(1);
    }

    int size()
    {
        return top + 1;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No elements in the stack!";
        }
        else
        {
            cout << "\nStacks elements are: \n";
            for (int i = top; i > -1; i--)
            {
                cout << i << ". " << arr[i] << ",\n";
            }
        }
    }
};

void menu()
{
    cout << "--- C++ Stacks using Template Demonstration --- \n\n";
    cout << "Operations: \n";
    cout << "   0.Menu\n";
    cout << "   1. Push\n";
    cout << "   2. Pop\n";
    cout << "   3. Display\n";
    cout << "   9. Quit\n";
}

int main()
{
    stack<string> st(10);
    int ch;
    string ele, data;
    menu();
    while (1)
    {
        cout << "\nEnter a command(0-3 or 9 to quit): ";
        cin >> ch;

        switch (ch)
        {
        case 0:
            menu();
            break;
        case 1:
            cout << "Enter the element: " << endl;
            cin >> data;
            st.push(data);
            break;

        case 2:
            ele = st.pop();
            cout << "The element popped is: " << ele;
            break;

        case 3:
            st.display();
            break;

        case 9:
            exit(1);
        default:
            cout << "Invalid Input \n\n";
        }

        cout << "\n\n";
    }

    getch();
    return 0;
}