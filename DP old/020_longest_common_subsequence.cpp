#include <bits/stdc++.h>
using namespace std;
int LCSRecursive(string a, string b, int m,  int n){
    if(n==0 || m==0) return 0;
    if(a[m-1] == b[n-1])
        return 1 + LCSRecursive(a,b,m-1,n-1);
    else
        return max(LCSRecursive(a,b,m-1,n),LCSRecursive(a,b,m,n-1));
}

vector<vector<int>> t(1001, vector<int>( 10001, -1));
int LCSMemorized(string a, string b, int m, int n){
    if(n==0 || m==0) return 0;
    if(t[m-1][n-1]!=-1) return t[m-1][n-1];
    if(a[m-1] == b[n-1])
        return t[m][n] = 1 + LCSRecursive(a,b,m-1,n-1);
    else
        return t[m][n] = max(LCSRecursive(a,b,m-1,n),LCSRecursive(a,b,m,n-1));
}
// Given two strings abcde ace. Length of Longest Common Subsequence is: 3
//     b |   a c e
// a ind | 0 1 2 3
//       | - - - - | n
//     0 | 0 0 0 0 |
// a   1 | 0 1 1 1 | 0
// b   2 | 0 1 1 1 | 1
// c   3 | 0 1 2 2 | 2
// d   4 | 0 1 2 2 | 3
// e   5 | 0 1 2 3 | 4
//       | - - - - |
int LCS(string a, string b) {
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
    return dp[m][n];
}
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)

int LCSOptimized(string a, string b) {
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
    return prev[n];
}
// Time Complexity: O(M*N)
// Space Complexity: O(max(M,N))

int main()
{
    string a, b;
    cout << "Enter two string whose Longest Common subsequence needs to be calculated: ";
    cin >> a;
    cin >> b;
    // cout << "Length of LCS of two strings are: " << LCS(a, b) << "\n";
    cout << "Length of LCS of two strings are: " << LCSOptimized(a, b) << "\n";
    return 0;
}