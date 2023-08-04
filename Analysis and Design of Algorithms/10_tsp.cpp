#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

int tsp(vector<vector<int>> dist, int setOfCities, int city, int numOfCities, vector<vector<int>> &dp)
{
    // base case
    if (setOfCities == ((1 << numOfCities) - 1))
        return dist[city][0];

    if (dp[setOfCities][city] != -1)
        return dp[setOfCities][city];

    // otherwise try all possible options
    int ans = INT_MAX;
    for (int choice = 0; choice < numOfCities; choice++)
    {
        // need to check if city is visited or not
        if ((setOfCities & (1 << choice)) == 0)
        {
            int subProb = dist[city][choice] + tsp(dist, setOfCities | (1 << choice), choice, numOfCities, dp);
            ans = min(ans, subProb);
        }
    }

    dp[setOfCities][city] = ans;
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    vector<vector<int>> dist = {
        // {0, 20, 42, 25},
        // {20, 0, 30, 34},
        // {42, 30, 0, 10},
        // {25, 34, 10, 0}
        {0, 7, 3, 12, 8},
        {3, 0, 6, 14, 9},
        {5, 8, 0, 6, 18},
        {9, 3, 5, 0, 11},
        {18, 14, 9, 8, 0}};

    cout << "Graph is: " << endl;
    for (vector<int> vec : dist)
    {
        for (int x : vec)
            if (x == INT_MAX)
                cout << "INF"
                     << "\t";
            else
                cout << x << "\t";

        cout << endl;
    }

    cout << "\nMinimum cost to travel all the cities and return is: " << tsp(dist, 1, 0, n, dp) << endl;

    // for (vector<int> vec : dp)
    // {
    //     for (int x : vec)
    //         if (x == INT_MAX)
    //             cout << "INF"
    //                  << "\t";
    //         else
    //             cout << x << "\t";

    //     cout << endl;
    // }

    getch();
    return 0;
}