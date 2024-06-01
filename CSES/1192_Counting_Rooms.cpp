//https://cses.fi/problemset/task/1192

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define ln '\n'

const int max_n=1000, max_m=1000;

char mp[max_n][max_m] = {0};
int ans = 0;
int n, m;

bool isValid(int i, int j)
{
    if (
            (i < 0) || (j < 0) || (i >= n) || (j >= m) || (mp[i][j] == '#')
            )
        return false;

    return true;
}

void bfs(int i, int j)
{
    ans++;
    queue<int> qi, qj;
    qi.push(i);
    qj.push(j);
    mp[i][j] = '#';
    while(qi.size())
    {
        i = qi.front();
        j = qj.front();
        qi.pop();
        qj.pop();

        // up
        if (isValid(i-1, j))
        {
            qi.push(i-1);
            qj.push(j);
            mp[i-1][j] = '#';
        }

        // down
        if (isValid(i+1, j))
        {
            qi.push(i+1);
            qj.push(j);
            mp[i+1][j] = '#';
        }

        // left
        if (isValid(i, j-1))
        {
            qi.push(i);
            qj.push(j-1);
            mp[i][j-1] = '#';
        }
        // right
        if (isValid(i, j+1))
        {
            qi.push(i);
            qj.push(j+1);
            mp[i][j+1] = '#';
        }

    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; j++)
            cin >> mp[i][j];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; j++)
            if (mp[i][j] == '.')
                bfs(i, j);

    cout << ans << '\n';
}