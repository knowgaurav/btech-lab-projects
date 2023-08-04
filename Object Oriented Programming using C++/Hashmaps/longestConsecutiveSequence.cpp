#include <iostream>
#include <conio.h>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, bool> myMap;
    int n, *arr;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        myMap[arr[i]] = true;
    }

    unordered_map<int, bool>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++)
    {
        //cout << it->first << " " << it->second << endl;
        if (myMap.find(it->first - 1) != myMap.end())
        {
            it->second = false;
        }
    }

    int msp = 0;
    int ml = 0;
    unordered_map<int, bool>::iterator it1;
    for (it1 = myMap.begin(); it1 != myMap.end(); it1++)
    {
        if (it1->second == true)
        {
            int tl = 1;
            int tsp = it1->first;

            while (myMap.find(tsp + tl) != myMap.end())
            {
                tl++;
            }

            if (tl > ml)
            {
                msp = tsp;
                ml = tl;
            }
        }
    }

    cout << msp << " " << msp + ml - 1;
    /*unordered_map<int, bool>::iterator it1;
    for (it1 = myMap.begin(); it1 != myMap.end(); it1++)
    {
        cout << it1->first << " " << it1->second << endl;
    }*/

    getch();
    return 0;
}