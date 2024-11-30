#include <bits/stdc++.h>
using namespace std;
// Given two strings heap pea. Length of Longest Common Subsequence is: 3
// Delete: m - LCS
// Insert: n - LCS
//     b |   p e a
// a ind | 0 1 2 3
//       | - - - - | n
//     0 | 0 0 0 0 |
// h   1 | 0 0 0 0 | 0
// e   2 | 0 0 1 1 | 1
// a   3 | 0 0 1 2 | 2
// p   4 | 0 1 1 2 | 3
//       | - - - - |
pair<int,int> convertByInsertDelete(string a, string b) {
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
    return {m-dp[m][n],n-dp[m][n]};
}
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)

pair<int,int> convertByInsertDeleteOptimized(string a, string b) {
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
    return {m-prev[n],n-prev[n]};
}
// Time Complexity: O(M*N)
// Space Complexity: O(max(M,N))

int main()
{
    string a, b;
    cout << "Converting 1st string to 2nd: ";
    cin >> a;
    cin >> b;
    pair<int,int> ans;
    // ans = convertByInsertDelete(a, b);
    // cout << "Conversion of 1st string to other by : " << ans.first << " delete " << ans.second << " insert" << "\n";
    ans = convertByInsertDeleteOptimized(a, b);
    cout << "Conversion of 1st string to other by : " << ans.first << " delete " << ans.second << " insert" << "\n";
    return 0;
}