//https://cses.fi/problemset/task/1667

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define ln '\n'

const int max_n = 1e5;
const int max_m = 2e5;
int n, m;

vector<int> nodes[max_n+1];
int parent[max_n+1] = {0};
stack<int> path;

bool bfs()
{
    queue<int> q;
    q.push(1);
    parent[1] = -1;
    while(q.size())
    {
        int i = q.front();
        q.pop();

        for (int j : nodes[i])
        {
            if (parent[j] != 0)
                continue;
            parent[j] = i;
            q.push(j);
        }
    }

    if (parent[n] == 0)
        return false;

    while (n != -1)
    {
        path.push(n);
        n = parent[n];
    }

    return true;
}

int main()
{
    FIO
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    if (!bfs())
    {
        cout << "IMPOSSIBLE\n";
        exit(0);
    }

    cout << path.size() << ln;
    while(path.size())
    {
        int i = path.top();
        path.pop();
        cout << i << ' ';
    }
    cout << ln;
}