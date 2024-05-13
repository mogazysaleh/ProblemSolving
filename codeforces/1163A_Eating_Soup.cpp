//https://codeforces.com/problemset/problem/1163/A

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


int main()
{
    FIO
    int n, m; cin >> n >> m;
    if (m <= (n>>1))
        cout << max(m, 1) << ln;
    else
        cout << n - m << ln;
}