//https://cses.fi/problemset/task/1617

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'

const ll p = 1e9+7;

ll bin_exp(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res*a)%p;
        a = (a*a)%p;
        b >>= 1;
    }
    return res;
}

int main()
{
    FIO
    ll n; cin >> n;
    cout << bin_exp(2, n) << '\n';
}