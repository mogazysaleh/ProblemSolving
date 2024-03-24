//https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


int arr[26] = {0};

int main()
{
    FIO
    string s; cin >> s;
    int odd_count = 0;
    for (char c: s)
    {
        arr[c - 'A']++;
        if (arr[c - 'A'] & 1)
            odd_count++;
        else
            odd_count--;
    }

    // the case where the solution does not exist
    if (
            (odd_count > 1) ||
            (s.size()&1) && (odd_count == 0)
            )
    {
        cout << "NO SOLUTION\n";
        exit(0);
    }


    int odd_index = -1;

    // left part
    for (int i = 0; i < 26; ++i)
        if (arr[i]&1)
            odd_index = i;
        else
            for (int j = 0; j < (arr[i] >> 1); ++j)
                cout << (char)(i + (int)'A');

    // middle part
    if (odd_index != -1)
        for (int j = 0; j < arr[odd_index]; ++j)
            cout << (char)(odd_index + (int)'A');
    arr[odd_index] = 0;

    // right part
    for (int i = 25; i >= 0; --i)
        for (int j = 0; j < (arr[i] >> 1); ++j)
            cout << (char)(i + (int)'A');
}