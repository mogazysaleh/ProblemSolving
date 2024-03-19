//https://cses.fi/problemset/task/1095

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
        int a, b, ans = 1; cin >> a >> b;

        b = b % (p-1);
        while (b)
        {
            if (b & 1)
                ans = ((ll)ans * (ll)a) % p;
            a = ((ll)a * (ll)a) % p;
            b >>= 1;
        }

        cout << ans << ln;
    }
}