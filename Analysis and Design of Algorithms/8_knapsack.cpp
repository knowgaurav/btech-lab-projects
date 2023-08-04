#include <iostream>
#include <conio.h>
#include <vector>
#include <set>

using namespace std;

struct comp
{
    bool operator()(const vector<double> &a, const vector<double> &b)
        const
    {
        return a[0] > b[0];
    }
};

class knapSack
{
    double finalValue = 0;
    int currentWeight = 0;
    vector<vector<double>> ans;
    set<vector<double>, comp> Item;

public:
    void insertItem(double val, double w, double indx)
    {
        Item.insert({val / w, val, w, indx});
    }

    int maxProfit(int W)
    {
        for (auto it : Item)
        {
            if (it[2] + currentWeight < W)
            {
                finalValue += it[1];
                currentWeight += it[2];
                ans.push_back(it);
            }
            else
            {
                int remW = W - currentWeight;
                finalValue += it[0] * remW;
                ans.push_back({it[0], (it[0] * remW), (double)remW, it[3]});
                break;
            }
        }

        for (auto it : ans)
        {
            cout << "Items added are : " << it[3]
                 << " Value = " << it[1] << ", Weight = " << it[2] << endl;
        }
        return finalValue;
    }
};

int main()
{
    knapSack K;

    int num = 0, W = 0;
    cout << "Enter the number of items: ";
    cin >> num;
    cout << "Enter the knapsack Weight: ";
    cin >> W;
    cout << endl;

    for (int i = 0; i < num; i++)
    {
        double value, weight;
        cout << "Enter item " << i + 1 << " value and weight: ";
        cin >> value >> weight;
        K.insertItem(value, weight, i + 1);
    }

    cout << endl;
    double profit = K.maxProfit(W);
    cout << "\nMax Value = " << profit;

    getch();
    return 0;
}
