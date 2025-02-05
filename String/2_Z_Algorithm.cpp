// Find the occurances of pattern in the text. Search for a substring in a large string.
// Z Algorithm
// We calculate a z-array through which we can find occurances of a pattern in text
// z(k): longest substring starting at k which is also the prefix of the string.
// k: 0 - n-1
// n: length of string
// a a b x a a b x c a a b x a a b x a y
// 0 1 0 0 4 1 0 0 0 8 1 0 0 5 1 0 0 1 0

// 1. Concatenate pattern + text and seperate them by a character not present in the string
//  pattern + $ + text  (optional to have $)
// 2. Calculate the z-array of this new new string efficiently
// 3. Look for the position where length of the pattern is equal to the z-array elements
//  required index(original text index) = index - (length of pattern + special character)
// Time Complexity: O(n^2)

// Optimized way to compute the z-array:
// Copy z-values for the substring 
// only calculate if sum of z-value + current index >= right boundary of the box(currently found substring)
// Time Complexity: O(|s|)
#include <bits/stdc++.h>
using namespace std;
long long ZAlgorithm(string s, long long n)
{
    long long ans = 0;
    vector<long long> z(s.size(), 0);
    long long r = 0;
    for (long long i = 1; i < s.size(); i += 1)
    {
        if (z[i] >= r - i)
        {
            long long j = 0;
            while (j < i && s[i + j] == s[j])
            {
                z[i + j] = z[j];
                j += 1;
            }
            z[i] = j;
            r = i + j;
            if (z[i] >= n)
                ans += 1;
        }
    }
    for(auto i:z){
        cout<<i<<" ";
    }
    cout<<"\n";
    return ans;
}
void solve(string s1, string s2)
{
    cout << "The frequency of " << s1 << " in " << s2 << " : " << ZAlgorithm(s1 + s2, s1.size()) << "\n";
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