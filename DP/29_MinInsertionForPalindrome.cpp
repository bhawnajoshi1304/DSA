// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
// Given a string s. In one step you can insert any character at any index of the string. Return the minimum number of steps to make s palindrome.
#include <bits/stdc++.h>
using namespace std;
int minInsertions(string s) {
    // Possible solution: mbdadbm
    // String:            mb ad m
    // Reversed string:   m da bm
    // LCS:               m  a  m
    //   m b a d m
    // m 1 1 1 1 1
    // d 1 1 1 2 2
    // a 1 1 2 2 2
    // b 1 2 2 2 2
    // m 1 2 2 2 3
    int n = s.size();
    // vector<vector<int>> dp(n, vector<int>(n, 0));
    // for (int i = 0; i < n; i += 1) {
    //     for (int j = 0; j < n; j += 1) {
    //         if (s[i] == s[n - 1 - j]) {
    //             dp[i][j] = (i == 0 || j == 0) ? 1 : dp[i - 1][j - 1] + 1;
    //         }
    //         else {
    //             dp[i][j] = max((i > 0) ? dp[i - 1][j] : 0, (j > 0) ? dp[i][j - 1] : 0);
    //         }
    //     }
    // }
    // return n - dp[n - 1][n - 1];

    int prevRow, prevRowCol;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < n; j += 1)
        {
            prevRow = dp[j];
            if (s[i] == s[n - 1 - j])
            {
                dp[j] = (i == 0 || j == 0) ? 1 : prevRowCol + 1;
            }
            else
            {
                dp[j] = max((i > 0) ? prevRow : 0, (j > 0) ? dp[j - 1] : 0);
            }
            prevRowCol = prevRow;
        }
    }
    return n - dp[n - 1];
}
int main() {
    string text;
    cout << "Enter string to convert into palindrome: ";
    cin >> text;
    cout << "Number of insertions to convert string to palindrome: " << minInsertions(text);
    return 0;
}