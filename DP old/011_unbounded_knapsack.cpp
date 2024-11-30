#include <bits/stdc++.h>
using namespace std;

// Assuming a knapsack with capacity 6 and 3 different weights available.
// The maximum value of knapsack is 15
// wt val  | 0 1 2 3 4  5  6 - w
//         | - - - - -  -  -  | n
//         | 0 0 0 0 0  0  0  | 0
//  2   5  | 0 0 5 5 10 10 15 | 1
//  3   6  | 0 0 5 6 10 11 15 | 2
//  4   7  | 0 0 5 6 10 11 15 | 3
//         | - - - - -  -  -  |
int UnboundedKnapsack(vector<int> &wt, vector<int> &val, int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i][j - wt[i - 1]] + val[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i += 1) {
    //     for (int j = 0; j <= capacity; j += 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][capacity];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W*N)

int UnboundedKnapsackOptimized(vector<int> &wt, vector<int> val, int n, int capacity) {
    vector<int> dp(capacity + 1, 0);  
    for (int i = 0; i < wt.size(); ++i) {
        for (int j = wt[i]; j <= capacity; ++j) {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }
    // for (int i = 0; i <= capacity; i += 1)
    //     cout << dp[i] << " ";
    return dp[capacity];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W)

int main() {
    int n, w;
    cout << "Enter number of weights: ";
    cin >> n;
    cout << "Enter weights for each weight: \n";
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i += 1) {
        cin >> wt[i];
    }
    cout << "Enter value for each weight: \n";
    for (int i = 0; i < n; i += 1) {
        cin >> val[i];
    }
    cout << "Enter capacity of knapsack: ";
    cin >> w;
    // cout << "Maximum value knapsack is: "<<UnboundedKnapsack(wt,val,n,w)<<"\n";
    cout << "Maximum value knapsack is: " << UnboundedKnapsackOptimized(wt, val, n, w) << "\n";
    return 0;
}