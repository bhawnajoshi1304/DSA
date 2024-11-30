// https://www.codechef.com/problems/CNTPRIME
#include <bits/stdc++.h>
using namespace std;
bool prime[10000001];
long long c[10000001];
void sieve()
{
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    memset(c, 0, sizeof(c));
    for (int p = 2; p * p < 10000001; p += 1)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i < 10000001; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p < 10000001; p += 1)
    {
        if (prime[p])
            c[p] = c[p - 1] + 1;
        else
            c[p] = c[p - 1];
    }
}
void solve()
{
    // Count number of primes between m and n inclusive
    long long m, n;
    cin >> m >> n;
    cout << c[n] - c[m - 1] << "\n";
}
int main()
{
    sieve();
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}