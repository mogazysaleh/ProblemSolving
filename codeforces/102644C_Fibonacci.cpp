//https://codeforces.com/problemset/gymProblem/102644/C

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long

const ull mod = 1e9+7;

void matrix_square(ull mat[2][2])
{
    ull a00 = mat[0][0], a01 = mat[0][1], a10 = mat[1][0], a11 = mat[1][1];

    mat[0][0] = ((a00 * a00) % mod + (a01 * a10) % mod) % mod;
    mat[0][1] = ((a00 * a01) % mod + (a01 * a11) % mod) % mod;
    mat[1][0] = ((a10 * a00) % mod + (a11 * a10) % mod) % mod;
    mat[1][1] = ((a10 * a01) % mod + (a11 * a11) % mod) % mod;
}

void matrix_mul(ull mat1[2][2], ull mat2[2][2])
{
    ull a00 = mat1[0][0], a01 = mat1[0][1], a10 = mat1[1][0], a11 = mat1[1][1];

    mat1[0][0] = ((a00 * mat2[0][0]) % mod + (a01 * mat2[1][0]) % mod) % mod;
    mat1[0][1] = ((a00 * mat2[0][1]) % mod + (a01 * mat2[1][1]) % mod) % mod;
    mat1[1][0] = ((a10 * mat2[0][0]) % mod + (a11 * mat2[1][0]) % mod) % mod;
    mat1[1][1] = ((a10 * mat2[0][1]) % mod + (a11 * mat2[1][1]) % mod) % mod;
}

ull get_nfib(ull n)
{
    ull a[2][2] = {
            {1, 1},
            {1, 0}
    };

    ull ans[2][2] = {
            {1, 0},
            {0, 1}
    };

    while (n)
    {
        if (n & 1)
            matrix_mul(ans, a);
        matrix_square(a);
        n >>= 1;
    }
    return ans[0][1];
}


int main()
{
    // diff
    ull n; cin >> n;
    cout << get_nfib(n);
}