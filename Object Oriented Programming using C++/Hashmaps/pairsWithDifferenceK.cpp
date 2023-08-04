#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

    //Edge Case
    if (k < 0)
        return 0;

    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++)
    {
        if (myMap.find(arr[i]) != myMap.end())
        {
            myMap[arr[i]]++;
        }
        else
        {
            myMap[arr[i]] = 1;
        }
    }

    int pairCount = 0;

    if (k == 0)
    {
        for (auto x : myMap)
        {
            if (x.second > 1)
                pairCount++;
        }
    }

    for (auto it : myMap)
    {
        int key = it.first - k;
        if (myMap.count(key))
            pairCount++;
    }

    cout << pairCount << endl;

    /*unordered_map<int, int>::iterator it1;
    for (it1 = myMap.begin(); it1 != myMap.end(); it1++)
    {
        cout << it1->first << " " << it1->second << endl;
    }*/

    getch();
    return 0;
}