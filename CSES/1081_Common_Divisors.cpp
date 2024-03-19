//https://cses.fi/problemset/task/1081

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'

const int max_x = 1e6;

int divs[max_x + 1] = {0};

int main()
{
    FIO
    int n; cin >> n;
    while (n--)
    {
        int x, i; cin >> x;
        for (i = 1; i*i < x; ++i)
        {
            if (x % i) continue;
            int q = x / i;
            divs[i]++;
            divs[q]++;
            if (divs[q] > 1)
                break;
        }
        if (i*i == x)
            divs[i]++;
    }
    for (int i = max_x; i >= 0; --i)
        if (divs[i] > 1)
        {
            cout << i << ln;
            exit(0);
        }
}