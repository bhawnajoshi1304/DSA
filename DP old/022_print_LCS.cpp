#include <bits/stdc++.h>
using namespace std;
// Given two strings abcde abfce. Length of Longest Common subsequence is: 3
//     b |   a b f c e
// a ind | 0 1 2 3 4 5
//       | - - - - - - | n
//     0 | 0 0 0 0 0 0 |
// a   1 | 0 1 1 1 1 1 | 0
// b   2 | 0 1 2 2 2 2 | 1
// c   3 | 0 1 2 2 3 3 | 2
// d   4 | 0 1 2 2 3 3 | 3
// e   5 | 0 1 2 2 3 4 | 4
//       | - - - - - - |
string LCS(string a, string b) {
    int m = a.size(), n = b.size();
    string s = "";
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i += 1) {
        for (int j = 1; j <= n; j += 1) {
            if (a[i - 1] == b[j - 1])
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
    int i = m, j = n;
    while(i>0 && j>0){
        if(a[i-1] == b[j-1]) {
            s.insert(s.begin(),a[i-1]);
            i-=1;
            j-=1;
        }else if(dp[i-1][j]>=dp[i][j-1]){
            i-=1;
        }else{
            j-=1;
        }
    }
    return s;
}
// Time Complexity: O(M*N)
// Space Complexity: O(M*N)

string LCSOptimized(string a, string b) {
    int m = a.size(), n = b.size();
    string s = "";
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] == b[j - 1])
                curr[j] = prev[j - 1] + 1;
            else
                curr[j] = max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    // for (int i = 0; i <= n; i += 1)
    //     cout << prev[i] << " ";
    // cout << "\n";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            s.insert(s.begin(),a[i - 1]);
            i--;
            j--;
        } else if (prev[j] > curr[j - 1]) {
            i--;  
        } else {
            j--;  
        }
    }
    return s;
}
// Time Complexity: O(M*N)
// Space Complexity: O(max(M,N))

int main() {
    string a, b;
    cout << "Enter two string whose Longest Common subsequence needs to be calculated: ";
    cin >> a;
    cin >> b;
    // cout << "Length of LCS of two strings are: " << LCS(a, b) << "\n";
    cout << "Length of LCS of two strings are: " << LCSOptimized(a, b) << "\n";
    return 0;
}