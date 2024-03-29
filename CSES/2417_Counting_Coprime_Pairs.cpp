//https://cses.fi/problemset/task/2417/

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define ln '\n'


// limits
const int max_n = 1e5;
const int max_x = 1e6;


// storage
int Xs[max_n + 1] = {0};
int Cd[max_x + 1] = {0};
int Ud[max_x + 1] = {0};

void fill_Cd(int n)
{
    for (int i = 0; i < n; ++i)
        for (int j = 1; j*j <= Xs[i]; ++j)
            if ( !(Xs[i] % j))
            {
                int q = Xs[i] / j;
                Cd[j]++;
                if (q != j)
                    Cd[q]++;
            }
}

void fill_Ud(int n, int x_high)
{
    // initialize all as (single) primes
    fill(Ud, Ud + max_x, -2);

    // 1 is not a prime
    Ud[1] = 1;


    for (int i = 2; i <= x_high; ++i)
    {
        // if i is a prime
        if (Ud[i] == -2)
        {
            // mobius function for a prime is -1
            Ud[i] = -1;

            // loop over all multiples of the prime
            for (int j = 2*i; j <= x_high; j+=i)
            {
                // if it is 0, then it is already a square
                if (Ud[j] == 0)
                    continue;

                // check if it is a square
                if ( !((j/i) % i) )
                    Ud[j] = 0;

                // if it is -2, then this is its least prime factor
                else if (Ud[j] == -2)
                    Ud[j] = -1;

                // invert the sign otherwise
                else
                    Ud[j] *= -1;
            }
        }
    }
}


int main()
{
    // take input
    int n, x_high = -1; cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> Xs[i];
        x_high = max(x_high, Xs[i]);
    }


    // calculate Cd
    fill_Cd(n);

    // calculate Ud
    fill_Ud(n, x_high);

    // perform summation
    ll ans = 0;
    for (int i = 1; i <= max_x; ++i)
        ans += (ll)Ud[i] * (ll)Cd[i]*( (ll)Cd[i]-1)/2;
    cout << ans << ln;

}