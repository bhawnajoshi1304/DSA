#include <bits/stdc++.h>
using namespace std;
// Count the minimum number of coins to give change for a given amount, given the various denomination of coins available.
// Assuming the amount to be 5 and coins available as [1,2,3]
// The count is: 2
// coins | 0 1 2 3 4 5 - w
//       | - - - - - - | n
//       |     -1      | 0
//  1    | 0 1 2 3 4 5 | 1
//  2    | 0 1 1 2 2 3 | 2
//  3    | 0 1 1 1 2 2 | 3

int CoinChangeII(vector<int> &coins, int n, int amount) {
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INT_MAX));
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        for (int j = 1; j <= amount; ++j) {
            if (coins[i - 1] <= j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] == INT_MAX ? INT_MAX : dp[i][j - coins[i - 1]] + 1);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // for (int i = 0; i <= n; i += 1) {
    //     for (int j = 0; j <= amount; j += 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W*N)

int CoinChangeIIOptimized(vector<int> &coins, int n, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (const int &coin : coins) {
        for (int j = coin; j <= amount; ++j) {
            if(dp[j - coin] != INT_MAX)
                dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }
    // for (int i = 0; i <= amount; i += 1)
    //     cout << dp[i] << " ";
    return dp[amount] == INT_MAX ? -1 : dp[amount];
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
    // cout << "Maximum ways of coin is: "<<CoinChangeII(coins,n,w)<<"\n";
    cout << "Maximum ways of coin is: " << CoinChangeIIOptimized(coins, n, w) << "\n";
    return 0;
}