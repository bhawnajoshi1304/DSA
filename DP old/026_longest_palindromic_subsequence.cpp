#include <bits/stdc++.h>
using namespace std;
// Givem string agbcba. Length of Longest Palindromic Subsequence is: 5 - abcba
// Reverse the string and find LCS with original string
// agbcba abcbga
//     b |   a g b c b a
// a ind | 0 1 2 3 4 5 6
//       | - - - - - - - | n
//     0 | 0 0 0 0 0 0 0 |
// a   1 | 0 1 1 1 1 1 1 | 0
// b   2 | 0 1 1 1 1 2 2 | 1
// c   3 | 0 1 2 2 2 2 2 | 2
// b   4 | 0 1 2 3 3 3 3 | 3
// g   5 | 0 1 2 3 4 4 4 | 2
// a   6 | 0 1 2 3 4 4 5 | 3
//       | - - - - - - - |
int palindromicSubsequence(string a) {
    int m = a.size();
    string b=a;
    reverse(b.begin(),b.end());
    vector<vector<int>> dp(m+1, vector<int>(m+1, 0));
    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            if (a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // for (int i = 0; i <= m; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    return dp[m][m];
}
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)

int palindromicSubsequenceOptimized(string a) {
    int m = a.size();
    string b=a;
    reverse(b.begin(),b.end());
    vector<int> prev(m+1, 0), curr(m+1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1] == b[j-1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    // for (int i = 0; i <= m; i += 1)
    //     cout << prev[i] << " ";
    // cout << "\n";
    return prev[m];
}
// Time Complexity: O(M*N)
// Space Complexity: O(max(M,N))

int main()
{
    string a;
    cout << "Enter a string: ";
    cin >> a;
    // cout << "Length of Longest Palindromic Subsequence: " << palindromicSubsequence(a) << "\n";
    cout << "Length of Longest Palindromic Subsequence: " << palindromicSubsequenceOptimized(a) << "\n";
    return 0;
}