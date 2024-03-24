//https://cses.fi/problemset/task/1754

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
        int a, b; cin >> a >> b;
        if (a < b)
            swap(a, b);
        b -= (a-b);
        if ((b < 0) || (b%3))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}