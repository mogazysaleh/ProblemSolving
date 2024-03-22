//https://cses.fi/problemset/task/1068

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'

int main()
{
    ll n; cin >> n; cout << n;
    while (n != 1)
    {
        if (n&1) // n is odd
            n = n*3+1;
        else
            n >>= 1;
        cout << ' ' << n;
    }
    cout << '\n';
}