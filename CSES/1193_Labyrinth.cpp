//https://cses.fi/problemset/task/1193

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);
#define ll long long
#define ull unsigned long long
#define ln '\n'

const int max_m = 1000, max_n = 1000;

int m, n;
int ai, aj, bi = -1, bj = -1;
char mp[max_n][max_m] = {0};
stack <char> path;
vector <char> ops = {'U', 'D', 'L', 'R'};

bool getDir(int& i, int& j, char c)
{
    if (c == 'U')
        i -= 1;
    else if (c == 'D')
        i += 1;
    else if (c == 'L')
        j -= 1;
    else if (c == 'R')
        j += 1;

    if (
            (i < 0) || (j < 0) || (i >= n) || (j >= m)
            )
        return false;

    return true;
}

void getInvDir(int& i, int& j, char c)
{
    if (c == 'U')
        i += 1;
    else if (c == 'D')
        i -= 1;
    else if (c == 'L')
        j += 1;
    else if (c == 'R')
        j -= 1;
}


void findB()
{
    queue<int> qi, qj;
    qi.push(ai);
    qj.push(aj);
    while (qi.size())
    {
        int i = qi.front();
        int j = qj.front();
        qi.pop();
        qj.pop();

        for (char op : ops)
        {
            int ii = i, jj = j;
            if (!getDir(ii, jj, op))
                continue;

            if (mp[ii][jj] == 'B')
            {
                mp[ii][jj] = op;
                bi = ii;
                bj = jj;
                return;
            }
            else if (mp[ii][jj] == '.')
            {
                qi.push(ii);
                qj.push(jj);
                mp[ii][jj] = op;
            }
        }
    }
}

void getPath()
{
    while (mp[bi][bj] != 'A')
    {
        path.push(mp[bi][bj]);
        getInvDir(bi, bj, mp[bi][bj]);
    }
}


int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == 'A')
                ai = i, aj = j;
        }

    findB();


    if (bi == -1)
    {
        cout << "NO\n";
        exit(0);
    }

    getPath();
    cout << "YES\n";
    cout << path.size() << '\n';
    while (path.size())
    {
        cout << path.top();
        path.pop();
    }
    cout << '\n';
}