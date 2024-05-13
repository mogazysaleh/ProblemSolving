//https://codeforces.com/problemset/problem/1016/A

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
    int c = 0;
    while (n--)
    {
        int a, ans = 0; cin >> a;
        ans += (a/m);
        c += (a%m);
        if (c >= m)
        {
            c -= m;
            ans++;
        }
        cout << ans << ' ';
    }
}