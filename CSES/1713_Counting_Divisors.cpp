//https://cses.fi/problemset/task/1713

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
    while (n--)
    {
        int x, ans = 0; cin >> x;
        for (int i = 1; i*i <= x; ++i)
        {
            if (x % i) continue;
            ans+=2;
            if ( (x / i) == i)
                ans--;
        }
        cout << ans << ln;
    }
}