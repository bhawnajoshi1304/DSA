
// https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
// You are given two strings s1 and s2. Your task is to find the length of the longest common substring among the given strings.
#include <bits/stdc++.h>
using namespace std;
long long longestCommonSubstr(string &s1, string &s2) {
    //   a b c d g h
    // a 1 0 0 0 0 0
    // c 0 0 1 0 0 0
    // d 0 0 0 2 0 0
    // g 0 0 0 0 3 0
    // h 0 0 0 0 0 4
    // r 0 0 0 0 0 0
    // long long ans = 0, n = s1.size(), m = s2.size();
    // vector<vector<long long>> dp(n, vector<long long>(m, 0));
    // for (long long i = 0; i < n; i += 1) {
    //     for (long long j = 0; j < m; j += 1) {
    //         if (s1[i] == s2[j])
    //             dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1;
    //         else
    //             dp[i][j] = 0;
    //         ans = max(ans, dp[i][j]);
    //     }
    // }
    // return ans;

    long long ans = 0, n = s1.size(), m = s2.size(), prevRowCol, prevRow;
    vector<long long> dp(m, 0);
    for (long long i = 0; i < n; i += 1) {
        for (long long j = 0; j < m; j += 1) {
            prevRow = dp[j];
            if (s1[i] == s2[j])
                dp[j] = (i == 0 || j == 0) ? 1 : prevRowCol + 1;
            else
                dp[j] = 0;
            prevRowCol = prevRow;
            ans = max(ans, dp[j]);
        }
    }
    return ans;
}
int main() {
    string text1, text2;
    cout << "Enter two strings: ";
    cin >> text1 >> text2;
    cout << "Length of longest common subsequences: " << longestCommonSubstr(text1, text2);
    return 0;
}