//https://codeforces.com/problemset/problem/199/A

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long

vector<int> fib((int)(1e5+1));

int main() {
    // initial values
    fib[0] = 0;
    fib[1] = 1;

    int n, i = 2;
    cin >> n;

    if (n == 0)
        cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
    else if (n == 1)
        cout << 1 << ' ' << 0 << ' ' << 0 << '\n';
    else
    {
        while(true)
        {
            fib[i] = fib[i-1] + fib[i-2];
            if (fib[i] == n)
                break;
            i++;
        }
        cout << fib[max(0, i-2)] << ' ' << fib[max(0, i-2)] << ' ' << fib[max(0, i-3)] << '\n';
    }
}