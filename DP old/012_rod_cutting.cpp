#include <bits/stdc++.h>
using namespace std;

// Assuming a rod of length 5 and 4 prices for different length of rod are available.
// Unbounded rod with wt->lenth val->price
// The maximum value of rod after cutting is 12
// len price  | 0 1 2 3 4  5  - w
//            | - - - - -  -  | n
//            | 0 0 0 0 0  0  | 0
//  1   2     | 0 2 4 6 8  10 | 1
//  2   5     | 0 2 5 7 10 12 | 2
//  3   7     | 0 2 5 7 10 12 | 3
//  4   8     | 0 2 5 7 10 12 | 4
//            | - - - - -  -  |
int RodCutting(vector<int> &len, vector<int> &price, int n, int length) {
    vector<vector<int>> dp(n + 1, vector<int>(length + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= length; ++j) {
            if (len[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - len[i - 1]] + price[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i += 1) {
    //     for (int j = 0; j <= length; j += 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][length];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W*N)

int RodCuttingOptimized(vector<int> &len, vector<int> price, int n, int length) {
    vector<int> dp(length + 1, 0);  
    for (int i = 0; i < len.size(); ++i) {
        for (int j = len[i]; j <= length; ++j) {
            dp[j] = max(dp[j], dp[j - len[i]] + price[i]);
        }
    }
    // for (int i = 0; i <= length; i += 1)
    //     cout << dp[i] << " ";
    return dp[length];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W)

int main() {
    int n, w;
    cout << "Enter number of rod lengths available: ";
    cin >> n;
    cout << "Enter lengths for each rod length: \n";
    vector<int> len(n), price(n);
    for (int i = 0; i < n; i += 1) {
        cin >> len[i];
    }
    cout << "Enter price for each rod length: \n";
    for (int i = 0; i < n; i += 1) {
        cin >> price[i];
    }
    cout << "Enter length of rod: ";
    cin >> w;
    // cout << "Maximum price of rod is: "<<RodCutting(len,price,n,w)<<"\n";
    cout << "Maximum price of rod is: " << RodCuttingOptimized(len, price, n, w) << "\n";
    return 0;
}