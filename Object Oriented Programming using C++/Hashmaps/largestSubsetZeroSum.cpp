#include <iostream>
#include <conio.h>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0, largestSum;
    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            largestSum = i + 1;
        }
        else
        {
            if (myMap.count(sum))
            {
                auto it = myMap.find(sum);
                largestSum = max(largestSum, i - it->second);
            }
            else
                myMap[sum] = i;
        }
    }

    cout << largestSum << endl
         << endl;

    unordered_map<int, int>::iterator it1;
    for (it1 = myMap.begin(); it1 != myMap.end(); it1++)
    {
        cout << it1->first << " " << it1->second << endl;
    }

    //95 -97 -387 -435 -5 -70 897 127 23 284

    getch();
    return 0;
}