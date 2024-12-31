// https://leetcode.com/problems/delete-operation-for-two-strings/
// Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same. In one step, you can delete exactly one character in either string.
#include <bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2) {
    // String1: s ea
    // String2:   ea t
    // LCS:       ea
    int n = word1.size(), m = word2.size();
    // vector<vector<int>> dp(n, vector<int>(m, 0));
    // for (int i = 0; i < n; i += 1) {
    //     for (int j = 0; j < m; j += 1) {
    //         if (word1[i] == word2[j])
    //             dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1;
    //         else
    //             dp[i][j] = max(i > 0 ? dp[i - 1][j] : 0, j > 0 ? dp[i][j - 1] : 0);
    //     }
    // }
    // return m + n - 2 * dp[n - 1][m - 1];
    vector<int> dp(m, 0);
    int prevRow, prevRowCol;
    for (int i = 0; i < n; i += 1) {
        for (int j = 0; j < m; j += 1) {
            prevRow = dp[j];
            if (word1[i] == word2[j])
                dp[j] = (i == 0 || j == 0) ? 1 : prevRowCol + 1;
            else
                dp[j] = max(i > 0 ? prevRow : 0, j > 0 ? dp[j - 1] : 0);
            prevRowCol = prevRow;
        }
    }
    return m + n - 2 * dp[m - 1];
}
int main() {
    string text1, text2;
    cout << "Enter two strings: ";
    cin >> text1 >> text2;
    cout << "Length of longest common subsequences: " << minDistance(text1, text2);
    return 0;
}