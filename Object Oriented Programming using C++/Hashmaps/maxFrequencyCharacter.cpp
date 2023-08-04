#include <iostream>
#include <conio.h>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string str;
    str = "abbcddsdeffffsbbcbb";

    unordered_map<char, int> ourMap;

    for (int i = 0; i < str.length(); i++)
    {
        if (ourMap.find(str[i]) != ourMap.end())
        {
            ourMap[str[i]]++;
        }
        else
        {
            ourMap[str[i]] = 1;
        }
    }

    int maxFreq = INT16_MIN;
    char maxChar = ' ';
    unordered_map<char, int>::iterator it;
    for (it = ourMap.begin(); it != ourMap.end(); it++)
    {
        //cout << it->first << " " << it->second << endl;
        if (it->second > maxFreq)
        {
            maxChar = it->first;
            maxFreq = it->second;
        }
    }

    cout << maxChar << endl;

    getch();
    return 0;
}