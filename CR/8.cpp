// https://www.codechef.com/problems/CNTPRIME
#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000000001
bool prime[SIZE];
void sieve()
{
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int p = 2; p * p < SIZE; p += 1)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i < SIZE; i += p)
                prime[i] = false;
        }
    }
}
void solve()
{
    // Count number of primes between m and n inclusive
    long long m, n;
    cin >> m >> n;
    for (long long i = m; i <= n; i += 1)
    {
        if (prime[i])
            cout << i << "\n";
    }
    cout << "\n";
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