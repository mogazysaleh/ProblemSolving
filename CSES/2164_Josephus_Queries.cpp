//https://cses.fi/problemset/task/2164/

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long

int get_index(int n, int k)
{
    if (n == 1)
        return 1;

    if ((ll)n >= (ll)2*k)
        return 2*k;

    int i = get_index((n >> 1) + (n & 1), k - (n >> 1));

    if (n & 1)
        i = 2*i-3;
    else
        i = 2*i-1;

    if (i < 1)
        i += (n+1);

    return i;
}

int main()
{
    FIO
    int q; cin >> q;
    while (q--)
    {
        int n, k; cin >> n >> k;
        cout << get_index(n, k) << '\n';
    }
}