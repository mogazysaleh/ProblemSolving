//https://cses.fi/problemset/task/1722/

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long

const ull mod = 1e9+7;

void matrix_square(ull arr[2][2])
{
    ull a00 = arr[0][0], a01 = arr[0][1], a10 = arr[1][0], a11 = arr[1][1];

    arr[0][0] = ((a00 * a00)%mod + (a01 * a10)%mod)%mod;
    arr[0][1] = ((a00 * a01)%mod + (a01 * a11)%mod)%mod;
    arr[1][0] = ((a10 * a00)%mod + (a11 * a10)%mod)%mod;
    arr[1][1] = ((a10 * a01)%mod + (a11 * a11)%mod)%mod;
}

void matrix_multiply(ull arr[2][2], ull arr1[2][2])
{
    ull a00 = arr[0][0], a01 = arr[0][1], a10 = arr[1][0], a11 = arr[1][1];

    arr[0][0] = ((a00 * arr1[0][0])%mod + (a01 * arr1[1][0])%mod)%mod;
    arr[0][1] = ((a00 * arr1[0][1])%mod + (a01 * arr1[1][1])%mod)%mod;
    arr[1][0] = ((a10 * arr1[0][0])%mod + (a11 * arr1[1][0])%mod)%mod;
    arr[1][1] = ((a10 * arr1[0][1])%mod + (a11 * arr1[1][1])%mod)%mod;
}

ull get_fib(ull n)
{
    ull a[2][2] = {
            {1, 1},
            {1, 0}
    };

    ull mat[2][2] = {
            {1, 0},
            {0, 1}
    };

    while (n)
    {
        if (n & 1)
            matrix_multiply(mat, a);
        matrix_square(a);
        n >>= 1;
    }

    return mat[0][1];
}

int main()
{
    ull n; cin >> n;
    cout << get_fib(n) << '\n';
}