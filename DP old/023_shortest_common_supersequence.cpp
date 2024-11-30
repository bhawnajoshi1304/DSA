#include <bits/stdc++.h>
using namespace std;
// Given two strings geek eke. Length of shortest common supersequence is: 5(geeke)
// Multiple solutions exist but length is constant: m + n - LCS(a,b,m,n)
//     b |   e k e
// a ind | 0 1 2 3
//       | - - - - | n
//     0 | 0 0 0 0 |
// g   1 | 0 0 0 0 | 0
// e   2 | 0 1 1 1 | 1
// e   3 | 0 1 1 2 | 2
// k   4 | 0 1 2 2 | 3
//       | - - - - |
int shortestCommonSubsequence(string a, string b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return m+n-dp[m][n];
}
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)

int shortestCommonSubsequenceOptimized(string a, string b) {
    int m = a.size(), n = b.size();
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i-1] == b[j-1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    // for (int i = 0; i <= n; i += 1)
    //     cout << prev[i] << " ";
    // cout << "\n";
    return m+n-prev[n];
}
// Time Complexity: O(M*N)
// Space Complexity: O(max(M,N))

int main()
{
    string a, b;
    cout << "Enter two string : ";
    cin >> a;
    cin >> b;
    // cout << "Length of shortest common subsequence of two strings are: " << shortestCommonSubsequence(a, b) << "\n";
    cout << "Length of shortest common subsequence of two strings are: " << shortestCommonSubsequenceOptimized(a, b) << "\n";
    return 0;
}