//https://codeforces.com/problemset/problem/1110/A

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'

int main()
{
    FIO
    int b, k; cin >> b >> k;
    int odds = 0;
    int a;
    k--;
    while (k--)
    {
        cin >> a;
        if ( (a&1)&&(b&1) )
            odds++;
    }
    cin >> a;
    if (a&1)
        odds++;
    if (odds&1)
        cout << "odd\n";
    else
        cout << "even\n";
}