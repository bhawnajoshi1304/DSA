// Find the occurances of pattern in the text. Search for a substring in a large string.
// KMP Algorithm
// For the pattern string prefix function is defined as an array of length n where
// pi(i) is the length of the proper suffix of the substring s[0...i].
// Proper prefix of a string is a prefix not equal to the string itself.

// abcadabc
// Proper Prefixes: a, ab, abc, abca, abcad, abcada, abcadab
// Proper Suffixes: c, bc, abc, dabc, adabc, cadabc, bcadabc

// pi(i) = {k: s[0...k-1] = s[i-(k-1)...i]}
// Pi function is also called the lps array (longest prefix suffix)

// a b c a d a b c
// 0 0 0 1 0 1 2 3

// To calculate it efficiently we notice that prefix function can only increase by 1 with previous index.
#include <bits/stdc++.h>
using namespace std;
void lps(vector<long long> &p, string s)
{
    for (long long i = 1; i < s.size(); i += 1)
    {
        if (s[i] == s[p[i - 1]])
            p[i] = p[i - 1] + 1;
    }
}
long long KMPAlgorithm(string s1, string s2)
{
    long long ans = 0;
    vector<long long> p(s1.size(), 0);
    lps(p, s1);
    long long j = 0;
    for (long long i = 0; i < s2.size(); i += 1)
    {
        if (s2[i] == s1[j])
            j += 1;
        else if (j > 0)
        {
            j = p[j - 1];
            i -= 1;
        }
        if (j == s1.size())
        {
            ans += 1;
            j = p[j - 1];
        }
    }
    return ans;
}
void solve(string s1, string s2)
{
    cout << "The frequency of " << s1 << " in " << s2 << " : " << KMPAlgorithm(s1, s2) << "\n";
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