#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;

/*int main()
{
    ofstream file("test.txt");
    string input;
    cout << "Enter the contents of the file: ";
    getline(cin, input);

    if (!file.is_open())
    {
        cout << "Sorry, not able to open the file!" << endl;
    }
    cout << "File made and content saved!" << endl;

    file << input;

    getch();
    file.close();
    return 0;
}*/

int main()
{
    ifstream file;
    string input, sinput;
    int n;
    cout << "Enter from which character to read: ";
    cin >> n;

    cout << "\nResult: ";
    file.open("test.txt");
    file.seekg(-10, ios::end);
    getline(file, sinput);
    cout << sinput;
    /*file.seekg(7, ios::beg);
    while (file)
    {
        getline(file, sinput);
        cout << sinput << endl;
    }*/
    getch();
    file.close();
    return 0;
}