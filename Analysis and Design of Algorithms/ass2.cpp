#include <iostream>
#include <conio.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

class solution
{
    map<string, int> m = {{"123456", 2}, {"175286", 2}, {"177286", 3}};
    map<int, int> m2 = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};

public:
    void checkString(string s1, string s2)
    {
        for (int i = 0; i < 6; i++)
        {
            if (s1[i] == s2[i])
            {
                m2[i]++;
            }
        }
    }

    int ans3()
    {
        auto it = m.begin();
        string s1 = it->first;
        for (auto it2 = next(it, 1); it2 != m.end(); ++it2)
        {
            checkString(s1, it2->first);
        }

        int flag = 0;
        for (auto itr = m2.begin(); itr != m2.end(); ++itr)
        {
            if (itr->second > 0)
                flag++;
        }

        // for (auto itr = m2.begin(); itr != m2.end(); ++itr)
        // {
        //     cout << '\t' << itr->first
        //          << '\t' << itr->second << '\n';
        // }
        return flag;
    }
};

int main()
{
    solution s;

    if (s.ans3())
        cout << "True";
    else
        cout << "False";

    getch();
    return 0;
}