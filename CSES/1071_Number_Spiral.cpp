//https://cses.fi/problemset/task/1071

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


int main()
{
    FIO
    int t; cin >> t;
    while (t--)
    {
        ull x, y; cin >> x >> y;
        ull n = max(x, y);
        if (n & 1)
            cout << (n*n) - (x-1) - (n-y);
        else
            cout << (n*n) - (y-1) - (n-x);
        cout << ln;
    }
}