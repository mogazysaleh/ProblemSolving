//https://cses.fi/problemset/task/1668/

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define ln '\n'

const int max_n = 1e5;
vector<int> nodes[max_n+1];
int team[max_n+1] = {0};

bool bfs(int i)
{
    if (team[i])
        return true;

    queue<int> q;
    team[i] = 1;
    q.push(i);

    while (q.size())
    {
        i = q.front();
        q.pop();

        for (int j : nodes[i])
        {
            if (team[i] == team[j])
                return false;
            else if (team[j])
                continue;

            team[j] = team[i]%2 + 1;
            q.push(j);
        }
    }

    return true;
}

int main()
{
    FIO
    int n, m; cin >> n >> m;
    while (m--)
    {
        int a, b; cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (!bfs(i))
        {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }

    for (int i = 1; i <= n; ++i)
        cout << team[i] << ' ';
    cout << '\n';
}