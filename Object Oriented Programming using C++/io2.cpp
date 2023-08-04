#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

void menu()
{
    cout << "\n--- C++ File Handling Demonstration --- \n\n";
    cout << "Operations: \n";
    cout << "   1. To Count\n";
    cout << "   2. To See File Contents\n";
    cout << "   3. To Edit File Contents\n";
    cout << "   4. To Quit\n";
}

int main()
{
    int ch, wordCount;
    string compare, input, fileName;
    cout << "Enter the file to be opened: ";
    cin >> fileName;

    menu();
    while (1)
    {
        cout << "\nEnter choice: ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "\nEnter the Word to be counted: ";
            cin >> compare;
            wordCount = 0;
            ifstream file(fileName);
            while (file >> input)
            {
                if (input == compare)
                {
                    ++wordCount;
                }
            }
            cout << "\n\"" << compare << "\" is present in the file " << wordCount << " times!";
            file.close();
        }
        else if (ch == 2)
        {
            cout << "\nContents of the file are: ";
            ifstream file(fileName);
            while (file >> input)
            {
                cout << input << " ";
            }
            file.close();
        }
        else if (ch == 3)
        {
            string newInput;
            ofstream file(fileName);
            cin.ignore();
            /*if (!file.is_open())
            {
                cout << "\nFile doesn't exists." << endl;
            }
            else
            {*/
            cout << "\nEnter new content: ";
            getline(cin, newInput);
            file << newInput;
            file.close();
        }

        else if (ch == 4)
        {
            cout << "\nExiting, thanks for using!";
            getch();
            exit(1);
        }
        else
        {
            cout << "\n#invalidInput";
            break;
        }
        cout << "\n\n";
    }
    return 0;
}