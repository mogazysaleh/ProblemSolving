//https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


int main()
{
    string s; cin >> s;
    char c = s[0];
    int len = 1, ans = 1;
    for (int i = 1; i < s.size(); ++i)
    {
        if (c != s[i])
        {
            len = 1;
            c = s[i];
        }
        else
            len++;
        ans = max(ans, len);
    }
    cout << ans << '\n';
}