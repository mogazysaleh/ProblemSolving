//https://codeforces.com/problemset/problem/17/A

#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ull unsigned long long
#define ll long long

const int max_n = 1000;

bool not_prime[max_n + 1] = {0};

vector<int> primes;

void sieving()
{
    not_prime[0] = not_prime[1] = true;
    for (size_t i = 2; i*i <= max_n; i++)
    {
        if (!not_prime[i])
        {
            for (size_t j = i*i; j <= max_n; j+=i)
                not_prime[j] = true;
        }
    }

    for (size_t i = 2; i <= max_n; i++)
        if(!not_prime[i])
            primes.push_back(i);
    

}

int main()
{
    FIO
    
    int n, k, cnt = 0; cin >> n >> k;

    sieving();

    for (size_t i = 1; i < primes.size(); i++)
    {
        int p = primes[i] + primes[i-1] + 1;

        if (p > n)
            break;

        if (!not_prime[p])
        {
            cnt++;
            if(cnt >= k)
                break;
        }
    }
    if (cnt >= k)
        cout << "YES\n";
    else
        cout << "NO\n";
}