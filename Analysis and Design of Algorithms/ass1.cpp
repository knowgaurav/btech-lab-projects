#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

class solution
{
    // vector<int> v = {20, 103, 3, 4, 25};
    map<string, int> m = {{"123456", 2}, {"175286", 2}};
    // map<string, int> m = {{"175286", 2}, {"293416", 3}, {"654321", 0}};
    map<int, int> m2 = {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}};
    // string s = "xyxxxyxyy";
    // string s = "yyyyyxx";

public:
    // bool ans(int k)
    // {
    //     for (int i = 0; i < v.size() - 2; i++)
    //     {

    //         int rem = k - v[i];
    //         unordered_set<int> s;
    //         for (int j = i + 1; v.size(); j++)
    //         {
    //             if (s.find(rem - v[j]) != s.end())
    //                 return true;

    //             s.insert(v[j]);
    //         }
    //     }
    //     return false;
    // }

    // int ans2()
    // {
    //     vector<char> temp;
    //     int cx = 0, cy = 0;
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         if (s[i] == 'x')
    //             cx++;
    //         else
    //             cy++;
    //     }

    //     for (int i = 0; i < cx; i++)
    //         temp.push_back('x');

    //     for (int i = 0; i < cy; i++)
    //         temp.push_back('y');

    //     int flip = 0;
    //     for (int i = 0; i < s.length(); i++)
    //     {
    //         if (s[i] != temp[i])
    //             flip++;
    //     }
    //     return flip;
    // }

    // void sort(map<string, int> &M)
    // {

    //     multimap<int, string> MM;
    //     for (auto &it : M)
    //     {
    //         MM.insert({it.second, it.first});
    //     }
    //     for (auto &it : MM)
    //     {
    //         cout << it.second << ' '
    //              << it.first << endl;
    //     }
    // }

    void traverseString(string s, int g)
    {
        for (int i = 0; i < s.length(); i++)
        {
            int d = s[i] - 48;
            if (m2.find(d) == m2.end())
            {
                m2[d] = 1;
                // --g;
            }
            else
            {
                m2[d]++;
                // --g;
            }
        }
    }

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
        // sort(m);

        // for (auto it : m)
        // {
        //     traverseString(it.first, it.second);
        // }

        // for (auto it : m2)
        // {
        //     if (it->second > 2)
        //         cout << it.first << " " << it.second;
        // }

        // for (auto itr = m2.begin(); itr != m2.end(); ++itr)
        // {
        //     cout << '\t' << itr->first
        //          << '\t' << itr->second << '\n';
        // }

        // for (auto it = m.begin(); it != next(it, 1); ++it)
        // {
        auto it = m.begin();
        string s1 = it->first;
        for (auto it2 = next(it, 1); it2 != m.end(); ++it2)
        {
            checkString(s1, it2->first);
        }
        // }

        for (auto itr = m2.begin(); itr != m2.end(); ++itr)
        {
            cout << '\t' << itr->first
                 << '\t' << itr->second << '\n';
        }

        return 0;
    }
};

int main()
{
    solution s;
    // cout << "Question 1 = " << s.ans(49) << endl;

    // cout << "Question 2 = " << s.ans2();

    s.ans3();

    getch();
    return 0;
}