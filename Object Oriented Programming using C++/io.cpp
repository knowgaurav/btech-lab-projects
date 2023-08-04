#include <iostream>
#include <fstream>

using namespace std;

void countWordFrequency(string *s, string compare, int size)
{
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        if (s[i] == compare)
            ++j;
    }
    cout << j << endl;
}

int main()
{
    /*string fileName;
    cin >> fileName;
    ofstream file(fileName, ios::app);

    //file << "Hello!" << endl;

    if (file.is_open())
    {
        cout << "success n00b!" << endl;
    }

    vector<string> v;
    v.push_back("Gaurav");
    v.push_back("Singh");

    for (string name : v)
    {
        file << name << " ";
    }

    file.close();*/

    ifstream file("tacos.txt");
    string ch;
    int word = 0;
    string input, com = "town";
    while (file >> ch)
    {
        if (ch == com)
        {
            word++;
        }
        // if (ch == 'n')
        //     line++;
    }
    cout << word;
    /*string *s1 = new string[word];
    int i;

    while (file >> input)
    {
        s1[i] = input;
        ++i;
    }
    //cout << i;
    countWordFrequency(s1, com, word);*/

    return 0;
}
