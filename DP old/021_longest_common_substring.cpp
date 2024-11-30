#include <bits/stdc++.h>
using namespace std;
// Given two strings abcde abfce. Length of Longest Common substring is: 3
//     b |   a b f c e
// a ind | 0 1 2 3 4 5
//       | - - - - - - | n
//     0 | 0 0 0 0 0 0 |
// a   1 | 0 1 0 0 0 0 | 0
// b   2 | 0 0 2 0 0 0 | 1
// c   3 | 0 0 0 0 1 0 | 2
// d   4 | 0 0 0 0 0 0 | 3
// e   5 | 0 0 0 0 0 1 | 4
//       | - - - - - - |
int LCS(string a, string b) {
    int m = a.size(), n = b.size(), maxLength = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLength = max(maxLength, dp[i][j]);
            } else
                dp[i][j] = 0;
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return maxLength;
}
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)

int LCSOptimized(string a, string b) {
    int m = a.size(), n = b.size(), maxLength = 0;
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] == b[j-1]) {
                curr[j] = prev[j - 1] + 1;
                maxLength = max(maxLength, curr[j]);
            } else
                curr[j] = 0;
        }
        prev = curr;
    }
    // for (int i = 0; i <= n; i += 1)
    //     cout << prev[i] << " ";
    // cout << "\n";
    return maxLength;
}
// Time Complexity: O(M*N)
// Space Complexity: O(max(M,N))

int main()
{
    string a, b;
    cout << "Enter two string whose Longest Common substring needs to be calculated: ";
    cin >> a;
    cin >> b;
    // cout << "Length of LCS of two strings are: " << LCS(a, b) << "\n";
    cout << "Length of LCS of two strings are: " << LCSOptimized(a, b) << "\n";
    return 0;
}