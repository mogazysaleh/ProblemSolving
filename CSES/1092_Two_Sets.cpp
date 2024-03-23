//https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'

int main()
{
    FIO
    ll n; cin >> n;
    ll sum = (n*(n+1)) >> 1;
    if(sum & 1)
    {
        cout << "NO" << ln;
        exit(0);
    }
    vector<bool> out(n+1);
    sum >>= 1;
    ll i = n, count = 0;
    while (sum)
    {
        if (sum >= i)
        {
            sum -= i;
            out[i] = true;
            count++;
        }
        i--;
    }
    cout << "YES\n";

    // first set
    cout << count << ln;
    for (i = 1; i <= n; ++i)
        if (out[i])
            cout << i << ' ';
    cout << ln;

    // second set
    cout << n - count << ln;
    for (i = 1; i <= n; ++i)
        if (!out[i])
            cout << i << ' ';
    cout << ln;

}