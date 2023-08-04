#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
class stack
{
    T *data;
    int index;
    int capacity;

public:
    stack()
    {
        data = new T[4];
        index = -1;
        capacity = 4;
    }

    int size()
    {
        return index + 1;
    }

    bool isEmpty()
    {
        if (index == -1)
            return true;
        else
            return false;

        //return index == -1;
    }

    void push(T ele)
    {
        if (index == capacity - 1)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];
            capacity *= 2;
            delete[] data;
            data = newData;
        }
        index++;
        data[index] = ele;
    }

    T pop()
    {
        if (isEmpty())
        {
            printf("Stack is empty!");
            return 0;
        }
        else
        {
            int temp = data[index];
            index--;
            return temp;
        }
    }

    T peek()
    {
        if (isEmpty())
        {
            printf("Stack is empty!");
            return 0;
        }
        else
        {
            return data[index];
        }
    }

    void display()
    {
        if (isEmpty())
        {
            printf("Stack is empty!");
        }
        else
        {
            for (int i = index; i > -1; i--)
                cout << data[i] << endl;
        }
    }
};

int main()
{
    stack<char> s;

    s.push(48);
    s.push(49);
    s.push(50);
    s.push(51);
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);

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
