//https://cses.fi/problemset/task/2187

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'

const ll max_n = 1e6;
const ll p = 1e9+7;

ll fact[max_n + 1];

void fill_fact()
{
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= max_n; ++i)
        fact[i] = (i*fact[i-1])%p;
}

ll bin_exp(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b&1)
            ans = (ans * a)%p;
        a = (a * a)%p;
        b >>= 1;
    }
    return ans;
}

ll comb(ll n, ll r)
{
    return (((fact[n] * bin_exp(fact[r], p-2))%p) * bin_exp(fact[n-r], p-2))%p;
}


int main()
{
    FIO
    ll n; cin >> n;
    string s; cin >> s;

    if (n&1)
    {
        cout << 0 << ln;
        exit(0);
    }

    fill_fact();

    ll l = 0, r = 0;
    for (char c : s)
    {
        if (c == ')')
            r++;
        else
            l++;

        if (r > l)
        {
            cout << 0 << ln;
            exit(0);
        }
    }

    if (l > (n>>1))
    {
        cout << 0 << ln;
        exit(0);
    }


    cout << (comb(n-r-l, (n>>1)-l) - comb(n-l-r, (n>>1)-1-l) + p)%p << ln;
}