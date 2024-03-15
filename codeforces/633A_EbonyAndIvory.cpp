//https://codeforces.com/problemset/problem/633/A

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long

int get_gcd(int a, int b, int& ai, int& bi)
{
    if (b == 0)
    {
        ai = 1;
        bi = 0;
        return a;
    }
    int g, ai0, bi0;
    g = get_gcd(b, a % b, ai0, bi0);
    ai = bi0;
    bi = ai0 - bi0 * (a / b);
    return g;
}

int main()
{
    int a, b, c, ai, bi, g; cin >> a >> b >> c;
    g = get_gcd(a, b, ai, bi);

    if (c % g)
    {
        cout << "No\n";
        exit(0);
    }

    // update values
    c /= g;
    a /= g;
    b /= g;
    ai *= c;
    bi *= c;

    int minx = ai + ceil(-1.0*ai/b)*b;
    int maxy = (c-a*minx)/b;

    if (maxy < 0)
        cout << "No\n";
    else
        cout << "Yes\n";
}