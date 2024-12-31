// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// Given a set of items, each with a weight and a value, represented by the array wt and val respectively. The task is to fill the knapsack with a given capacity in such a way that we can get the maximum profit. Return the maximum profit. Each item can be taken any number of times.
#include <bits/stdc++.h>
using namespace std;
long long knapSack(vector<long long> &val, vector<long long> &wt, long long capacity) {
    long long n = val.size();
    // vector<vector<long long>> dp(n+1,vector<long long>(capacity+1));
    // for(long long i=1;i<=n;i+=1){
    //     for(long long j=1;j<=capacity;j+=1){
    //         if(j>=wt[i-1])
    //         dp[i][j]=max(dp[i][j-wt[i-1]]+val[i-1],dp[i-1][j]);
    //         else
    //         dp[i][j]=dp[i-1][j];
    //     }
    // }
    // return dp[n][capacity];

    vector<long long> dp(capacity + 1);
    for (long long i = 1; i <= n; i += 1)
    {
        for (long long j = 1; j <= capacity; j += 1)
        {
            if (j >= wt[i - 1])
                dp[j] = max(dp[j - wt[i - 1]] + val[i - 1], dp[j]);
        }
    }
    return dp[capacity];
}

int main() {
    long long capacity, n;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;
    vector<long long> wt(n), val(n);
    cout << "Enter the weights of items seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter the value of items seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> val[i];
    cout << "Knapsack total value: " << knapSack(val, wt, capacity) << "\n";
    return 0;
}