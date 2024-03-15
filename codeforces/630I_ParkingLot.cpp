//https://codeforces.com/problemset/problem/630/I

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long

vector<ull> fact(31);

ull bin_exp(ull b, ull e)
{
    ull res = 1;
    while (e)
    {
        if (e & 1)
            res *= b;

        b *= b;
        e >>= 1;
    }
    return res;
}

void fill_fact()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 31; ++i)
        fact[i] = fact[i-1]*i;
}

int main()
{
    int n; cin >> n;

    ull ans = 0;
    fill_fact();

    // corners
    ans += bin_exp(4, n-2) * 3 * 2;

    // middle
    if (n > 3)
        ans += bin_exp(4, n-3) * 3 * 3 * (n-3);

    cout << ans << '\n';
}