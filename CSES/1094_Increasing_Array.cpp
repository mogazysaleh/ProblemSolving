//https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


int main()
{
    FIO
    int n; cin >> n;
    ll a0; cin >> a0;
    n--;
    ll ans = 0;
    while (n--)
    {
        ll a; cin >> a;
        ans += max(a0 - a, (ll)0);
        a0 = max(a0, a);
    }
    cout << ans << '\n';
}