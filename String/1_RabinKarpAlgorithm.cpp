// Find the occurances of pattern in the text. Search for a substring in a large string.
// Rabim Karp Algorithm
// Instead of matching the string character by character we match the hash value.
// A good hash function must have less collisions.

// rollHash(s) = [ s[0] + s[1]*p + s[2]*p^2 + ... +s[n-1]*p^(n-1)] mod m

// for case insensitive               p = 31
// for case sensitive                 p = 53

// m should be large as probability of collision is 1/m         m = 10**9 + 7

// This hash function is good but complexity is high
// To reduce which we use rolling hash

// rollHash(s[1...n]) = (d * ( rollHash(s[0...n-1] - h*s[0] ) + s[n]) mod q
// d = number of possible alpabets
// h = d^(n-1)
// q = prime number not very large as
// rolling hash of pattern could be small and rolling hash of same text is large
// skippig some potential matches
// This hash function is similar to decimal representation where d=10

#include <bits/stdc++.h>
#define mod 101
#define d 256
using namespace std;
long long rollHash(string s)
{
    long long ans = 0;
    for (long long i = 0; i < s.size(); i += 1)
    {
        ans = (ans * d + s[i]) % mod;
    }
    return ans % mod;
}
long long rollHash(char a, char b, long long prev, long long n)
{
    long long h = 1;
    for (long long i = 0; i < n - 1; i += 1)
        h = (h * d) % mod;
    long long ans = (d * (prev - h * a) + b) % mod;
    if (ans < 0)
        ans += mod;
    return ans;
}
bool match(string s1, string s2)
{
    for (long long i = 0; i < s1.size(); i += 1)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}
long long RabinKarp(string s1, string s2)
{
    if (s2.size() < s1.size())
        return 0;
    long long n = s1.size();
    long long pattern = rollHash(s1);
    long long ans = 0;
    long long prev = rollHash(s2.substr(0, n));
    if (pattern == prev)
        ans += 1;
    for (long long i = 1; i + n - 1 < s2.size(); i += 1)
    {
        long long tmp = rollHash(s2[i - 1], s2[i + n - 1], prev, n);
        if (tmp == pattern && match(s1, s2.substr(i, i + n)))
            ans += 1;
        prev = tmp;
    }
    return ans;
}
void solve(string s1, string s2)
{
    cout << "The frequency of " << s1 << " in " << s2 << " : " << RabinKarp(s1, s2) << "\n";
}
int main()
{
    char choice = 'y';
    solve("abc", "abcbcabc");
    cout << "Test more inputs? (y/n): ";
    cin >> choice;
    while (choice == 'y')
    {
        string s1, s2;
        cout << "Enter pattern: ";
        cin >> s1;
        cout << "Enter text: ";
        cin >> s2;
        solve(s1, s2);
        cout << "Test more inputs? (y/n): ";
        cin >> choice;
    }
    return 0;
}