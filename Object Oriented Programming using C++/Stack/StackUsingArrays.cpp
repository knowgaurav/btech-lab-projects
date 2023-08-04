#include <iostream>
#include <conio.h>

using namespace std;

class stackUsingArray
{
    int *stack;
    int top;
    int capacity;

public:
    stackUsingArray(int totalSize)
    {
        stack = new int[totalSize];
        top = 0;
        capacity = totalSize;
    }

    int size()
    {
        return top;
    }

    bool isEmpty()
    {
        /*if(top == 0)
            return true;
        else
            return false;*/
        return top < 0;
    }

    void push(int element)
    {
        if (top == capacity)
        {
            cout << "Error! Stack is full." << endl;
            return;
        }
        else
            stack[top++] = element;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Error! Stack is empty." << endl;
            return -1;
        }
        return stack[top--];
        //top--;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Error! Stack is empty." << endl;
            return -1;
        }
        return stack[top - 1];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Error! Stack is empty." << endl;
        }
        else
        {
            cout << "The stack is: " << endl;
            for (int i = top; i > -1; i--)
            {
                cout << "|" << stack[i] << "|" << endl;
            }
            cout << "^^^^";
        }
    }
};

int main()
{
    stackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << "The top element is: " << s.peek() << endl;
    cout << endl;
    s.display();

    cout << "\n\nPoping an element: " << endl;
    cout << s.pop();

    cout << "\n\nPoping an element: " << endl;
    cout << s.pop();

    cout << "\n\nPoping an element: " << endl;
    cout << s.pop();

    cout << "\n\nPoping an element: " << endl;
    cout << s.pop();

    cout << "\n\nPoping an element: " << endl;
    cout << s.pop();

    getch();
    return 0;
}