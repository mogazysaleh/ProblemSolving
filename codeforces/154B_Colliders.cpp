//https://codeforces.com/problemset/problem/17/A

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long

const int max_n = 1e5;

int current[max_n + 1] = {0};

int check_conflict(int c)
{
    if (current[c])
        return current[c];

    // loop to find all divisors of c
    for (int i = 2; i * i <= c; ++i)
    {
        if (c % i == 0) // check if i is a divisor of c
        {
            int q = c/i;

            // check if another collider is set
            if (current[i])
                return current[i];
            else if (current[q])
                return current[q];
        }
    }

    // a return == 0 means there are no conflicts
    return 0;
}

int set_collider(int c)
{
    // check if there is a conflict
    int conflict = check_conflict(c);
    if (conflict) // return should be 0 if there are no conflicts
        return conflict;

    // set collider
    current[c] = c;
    for (int i = 2; i * i <= c; ++i)
        if (c % i == 0)
            current[i] = current[c/i] = c;

    // return == 0 means that the collider has been successfully set
    return 0;
}

int clear_collider(int c)
{
    // check if collider still exists
    int conflict = check_conflict(c);
    if (conflict != c) // return must be c if collider is still there
        return conflict;

    // unset collider
    current[c] = 0;
    for (int i = 2; i * i <= c; ++i)
        if (c % i == 0)
            current[i] = current[c/i] = 0;

    // return == c means that the collider has been successfully unset
    return c;
}

int main()
{
    FIO
    int n, m; cin >> n >> m;

    while (m--)
    {
        char c; cin >> c;
        int i; cin >> i;

        if (c == '+')
        {
            int s = set_collider(i);
            if (s == 0)
                cout << "Success\n";
            else if (i == s)
                cout << "Already on\n";
            else
                cout << "Conflict with " << s << '\n';
        }
        else
        {
            int s = clear_collider(i);
            if (s == i)
                cout << "Success\n";
            else
                cout << "Already off\n";
        }
    }
}