//https://cses.fi/problemset/task/1618

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


int main()
{
    int n, ans = 0; cin >> n;
    while(n)
    {
        n /= 5;
        ans += n;
    }
    cout << ans << ln;
}