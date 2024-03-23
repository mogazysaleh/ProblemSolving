//https://cses.fi/problemset/task/1072

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


ll comb2(ll n)
{
    return (n*(n-1)) >> 1;
}

int main()
{
    FIO
    ll n; cin >> n;
    for (int i = 1; i <= n; ++i)
        cout << comb2(i*i) - 2*(i-2)*(2*i-2) << '\n';
}