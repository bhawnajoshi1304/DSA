#include <bits/stdc++.h>
using namespace std;
// Count the number of ways to give change for a given amount, given the various denomination of coins available.
// Analogous to subset sum problem
// Assuming the amount to be 5 and coins available as [1,2,3]
// The count is: 5
// coins | 0 1 2 3 4 5 - w
//       | - - - - - - | n
//       | 0 0 0 0 0 0 | 0
//  1    | 1 1 1 1 1 1 | 1
//  2    | 1 1 2 2 3 3 | 2
//  3    | 1 1 2 3 4 5 | 3
int CoinChangeI(vector<int> &coins, int n, int amount) {
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= amount; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= coins[i - 1]) {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }
    // for (int i = 0; i <= n; i += 1) {
    //     for (int j = 0; j <= amount; j += 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][amount];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W*N)

int CoinChangeIOptimized(vector<int> &coins, int n, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (const int &coin : coins) {
        for (int j = coin; j <= amount; ++j) {
            dp[j] += dp[j - coin];
        }
    }
    // for (int i = 0; i <= amount; i += 1)
    //     cout << dp[i] << " ";
    return dp[amount];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W)

int main() {
    int n, w;
    cout << "Enter number of coin dominations available: ";
    cin >> n;
    cout << "Enter amounts for each coin domination: \n";
    vector<int> coins(n);
    for (int i = 0; i < n; i += 1) {
        cin >> coins[i];
    }
    cout << "Enter amount of coin: ";
    cin >> w;
    // cout << "Maximum ways of coin is: "<<CoinChangeI(coins,n,w)<<"\n";
    cout << "Maximum ways of coin is: " << CoinChangeIOptimized(coins, n, w) << "\n";
    return 0;
}