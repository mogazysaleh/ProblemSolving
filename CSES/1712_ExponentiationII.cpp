//https://cses.fi/problemset/task/1712

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'

const int p = 1e9+7;


int main()
{
    FIO
    int n; cin >> n;
    while (n--)
    {
        int a, b, c, sub = 1, ans = 1; cin >> a >> b >> c;
        int p1 = p-1;

        while (c)
        {
            if (c & 1)
                sub = ((ll)sub * (ll)b) % p1;
            b = ((ll)b * (ll)b) % p1;
            c >>= 1;
        }

        while (sub)
        {
            if (sub & 1)
                ans = ((ll)ans * (ll)a) % p;
            a = ((ll)a * (ll)a) % p;
            sub >>= 1;
        }

        cout << ans << ln;
    }
}