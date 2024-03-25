//https://cses.fi/problemset/task/2165

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'

queue<pair<int, int>> q;

void solve_tower(int from, int to, int aux, int n)
{
    // base case
    if (n == 1)
    {
        q.push({from, to});
        return;
    }

    // n-1 tower from -> aux
    solve_tower(from, aux, to, n-1);

    // current from -> to
    q.push({from, to});

    // n-1 tower aux -> to
    solve_tower(aux, to, from, n-1);
}

int main()
{
    FIO
    int n; cin >> n;
    solve_tower(1, 3, 2, n);

    cout << q.size() << ln;
    while (q.size())
    {
        cout << q.front().first << ' ' << q.front().second << ln;
        q.pop();
    }
}