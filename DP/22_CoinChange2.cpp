// https://leetcode.com/problems/coin-change-ii/
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money. Return the number of combinations that make up that amount.
#include <bits/stdc++.h>
using namespace std;
int change(int amount, vector<int> &coins) {
    vector<uint64_t> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i += 1)
    {
        for (int j = coins[i]; j <= amount; j += 1)
        {
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
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
    cout << "Minimum coins required to make total amount: " << change(amount, coins) << "\n";
    return 0;
}