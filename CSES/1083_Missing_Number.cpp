//https://cses.fi/problemset/submit/1083/

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


int main()
{
    int n; cin >> n;
    vector<bool>v(n+1);
    n--;
    while(n--)
    {
        int a; cin >> a;
        v[a] = true;
    }
    for (int i = 1; i < v.size(); ++i)
        if (!v[i])
            cout << i << '\n';
}