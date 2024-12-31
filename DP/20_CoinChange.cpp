// https://leetcode.com/problems/coin-change/
// You are given an integer array coins representing coins of different denominations and an integer amount. Return the fewest number of coins that you need to make up that amount.
#include <bits/stdc++.h>
using namespace std;
int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, 1e4 + 1);
    for (int i = 0; i < coins.size(); i += 1)
    {
        dp[0] = 0;
        for (int j = coins[i]; j <= amount; j++)
        {
            dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
        }
    }
    return (dp[amount] == 1e4 + 1) ? -1 : dp[amount];
}
int main() {
    long long amount, n;
    cout << "Enter number of coins: ";
    cin >> n;
    cout << "Enter total amount to be paid: ";
    cin >> amount;
    vector<int> coins(n);
    cout << "Enter the different denominations of coins seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> coins[i];
    cout << "Minimum coins required to make total amount: " << coinChange(coins, amount) << "\n";
    return 0;
}