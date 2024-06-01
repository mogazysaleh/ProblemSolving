//https://cses.fi/problemset/task/1666

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define ln '\n'

const int max_n = 1e5;
int m, n;

vector<int> arr[max_n+1];
bool visited[max_n+1] = {0};
vector<int> chosen;

void bfs(int i)
{
    chosen.push_back(i);
    queue<int> qi;
    qi.push(i);
    visited[i] = true;
    while(qi.size())
    {
        i = qi.front();
        qi.pop();

        for (int j : arr[i])
            if (!visited[j])
            {
                qi.push(j);
                visited[j] = true;
            }

    }
}

int main()
{
    FIO
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            bfs(i);

    cout << chosen.size() - 1 << ln;
    for (int i = 1; i < chosen.size(); i++)
        cout << chosen[i-1] << ' ' << chosen[i] << ln;
}