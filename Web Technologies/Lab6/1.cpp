#include <bits/stdc++.h>

#define ll long long
#define m 1000000007
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;

ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

int main()

{

    fast;
    ll t, n, a, i, j, k;

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> v;
        for (i = 0; i < n; i++)
        {
            cin >> a;
            v.push_back(a);
        }

        ll ans = 0, s;

        for (i = 0; i < 32; i++)

        {
            ll count1bit = 0;
            for (j = 0; j < n; j++)

            {
                if (v[j] & (1 << i))

                {
                    count1bit += 1;
                }
            }
            s = power(2, count1bit, m) - 1;
            s = (s * power(2, i, m)) % m;
            ans = (ans + s) % m;
        }
        cout << ans << endl;
    }
}