#include <iostream>
#include <conio.h>

using namespace std;

#define MAXN 100001

int sieve[MAXN];

void sieveforPrimeFactors()
{
    for (int i = 0; i < MAXN; i++)
        sieve[i] = i;

    for (int i = 2; i * i < MAXN; i++)
    {
        if (sieve[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
            {
                if (sieve[j] == j)
                    sieve[j] = i;
            }
        }
    }
}

int main()
{
    int num;
    cin >> num;

    sieveforPrimeFactors();

    while (num != 1)
    {
        cout << sieve[num] << " ";
        num = num / sieve[num];
    }

    getch();
    return 0;
}

// // C++ program to find prime factorization of a
// // number n in O(Log n) time with precomputation
// // allowed.
// #include "bits/stdc++.h"
// #include <conio.h>
// using namespace std;

// #define MAXN 100001

// // stores smallest prime factor for every number
// int spf[MAXN];

// // Calculating SPF (Smallest Prime Factor) for every
// // number till MAXN.
// // Time Complexity : O(nloglogn)
// void sieve()
// {
//     spf[1] = 1;
//     for (int i = 2; i < MAXN; i++)

//         // marking smallest prime factor for every
//         // number to be itself.
//         spf[i] = i;

//     // separately marking spf for every even
//     // number as 2
//     for (int i = 4; i < MAXN; i += 2)
//         spf[i] = 2;

//     for (int i = 3; i * i < MAXN; i++)
//     {
//         // checking if i is prime
//         if (spf[i] == i)
//         {
//             // marking SPF for all numbers divisible by i
//             for (int j = i * i; j < MAXN; j += i)

//                 // marking spf[j] if it is not
//                 // previously marked
//                 if (spf[j] == j)
//                     spf[j] = i;
//         }
//     }
// }

// // A O(log n) function returning primefactorization
// // by dividing by smallest prime factor at every step
// vector<int> getFactorization(int x)
// {
//     vector<int> ret;
//     while (x != 1)
//     {
//         ret.push_back(spf[x]);
//         x = x / spf[x];
//     }
//     return ret;
// }

// // driver program for above function
// int main(int argc, char const *argv[])
// {
//     // precalculating Smallest Prime Factor
//     sieve();
//     int x = 12246;
//     cout << "prime factorization for " << x << " : ";

//     // calling getFactorization function
//     vector<int> p = getFactorization(x);

//     for (int i = 0; i < p.size(); i++)
//         cout << p[i] << " ";
//     cout << endl;

//     getch();
//     return 0;
// }

// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     int n = 315;
//     vector<int> ans;
//     int i = 2;
//     while(n>1){
//         while(n%i == 0){
//          ans.push_back(i);
//          n = n/i;
//         }
//         i++;
//     }
    
    
//     for(int i=0; i<ans.size(); i++){
//         cout << ans[i] << "X";
//     }
//     return 0;
// }