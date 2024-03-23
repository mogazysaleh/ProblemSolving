//https://cses.fi/problemset/task/1070

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
    if (n == 1)
        cout << 1 << ln;
    else if (n <= 3)
        cout << "NO SOLUTION" << ln;
    else
    {
        for (int i = 2; i <= n; i+=2)
            cout << i << " ";
        for (int i = 1; i <= n; i+=2)
            cout << i << " ";
        cout << "\n";
    }
}