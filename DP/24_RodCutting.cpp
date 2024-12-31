// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// Given a rod of length n(size of price) inches and an array of prices, price. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.
#include <bits/stdc++.h>
using namespace std;
long long cutRod(vector<long long> &price)
{
    long long n = price.size();
    // vector<vector<long long>> dp(n + 1, vector<long long>(n + 1));
    // for (long long i = 1; i <= n; i += 1)
    // {
    //     for (long long j = 1; j <= n; j += 1)
    //     {
    //         if (j >= i)
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - i] + price[i - 1]);
    //         else
    //             dp[i][j] = dp[i - 1][j];
    //     }
    // }
    // return dp[n][n];
    vector<long long> dp(n + 1);
    for (long long i = 1; i <= n; i += 1)
    {
        for (long long j = 1; j <= n; j += 1)
        {
            if (j >= i)
                dp[j] = max(dp[j], dp[j - i] + price[i - 1]);
        }
    }
    return dp[n];
}
int main() {
    long long capacity, n;
    cout << "Enter rod length: ";
    cin >> n;
    vector<long long> price(n);
    cout << "Enter the price of rod length i+1 seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> price[i];
    cout << "Knapsack total value: " << cutRod(price) << "\n";
    return 0;
}