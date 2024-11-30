#include <bits/stdc++.h>
using namespace std;
// Find the maximum number of pieces you can cut from a given ribbon of length length, using an array of specified ribbons of cuts you can make. 
// Assuming the length of ribbon to be 7 and ribbons available as [1,2,3]
// The count is: 3
// ribbons |  0  1  2  3  4  5  6  7 - length
//         |  -  -  -  -  -  -  -  - | n
//         |  0 -1 -1 -1 -1 -1 -1 -1 | 0
//    1    |  0 -1  1 -1  2 -1  3 -1 | 1
//    2    |  0 -1  1  1  2  2  3  3 | 2
//    3    |  0 -1  1  1  2  2  3  3 | 3
int RibbonCut(vector<int> &ribbons, int n, int length) {
    vector<vector<int>> dp(n + 1, vector<int>(length + 1, -1));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= length; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= ribbons[i - 1] && dp[i][j - ribbons[i - 1]] != -1) {
                dp[i][j] = max(dp[i][j], dp[i][j - ribbons[i - 1]] + 1);
            }
        }
    }
    // for (int i = 0; i <= n; i += 1) {
    //     for (int j = 0; j <= length; j += 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][length];
}
// Time Complexity: O(W*length)
// Space Complexity: O(W*length)

int RibbonCutOptimized(const vector<int>& ribbons, int n, int length) {
    vector<int> dp(length + 1, -1);
    dp[0] = 0;
    for (int ribbon : ribbons) {
        for (int i = ribbon; i <= length; ++i) {
            if (dp[i - ribbon] != -1) {
                dp[i] = max(dp[i], dp[i - ribbon] + 1);
            }
        }
    }
    // for (int i = 0; i <= length; i += 1)
    //     cout << dp[i] << " ";
    return dp[length];
}
// Time Complexity: O(W*length)
// Space Complexity: O(W)

int main() {
    int n, length;
    cout << "Enter ribbons of ribbon available: ";
    cin >> n;
    cout << "Enter length for each ribbon: \n";
    vector<int> ribbons(n);
    for (int i = 0; i < n; i += 1) {
        cin >> ribbons[i];
    }
    cout << "Enter length of ribbon: ";
    cin >> length;
    // cout << "Maximum number of ribbon cut is: " << RibbonCut(ribbons,n,length)<<"\n";
    cout << "Maximum number of ribbon cut is: " << RibbonCutOptimized(ribbons, n, length) << "\n";
    return 0;
}