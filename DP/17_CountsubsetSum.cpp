// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.
#include <bits/stdc++.h>
using namespace std;
long long perfectSum(vector<long long> &arr, long long target) {
    long long n = arr.size();
    // vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
    // dp[0][0] = 1;
    // for (long long i = 1; i <= n; i += 1) {
    //     dp[i][0] = 1;
    //     for (long long j = 0; j <= target; j += 1) {
    //         if (j >= arr[i - 1])
    //             dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
    //         else
    //             dp[i][j] = dp[i - 1][j];
    //     }
    // }
    // return dp[n][target];
    vector<long long> dp(target + 1, 0), prev(target + 1, 0);
    dp[0] = prev[0] = 1;
    for (long long i = 1; i <= n; i += 1) {
        dp[0] = 1;
        for (long long j = 0; j <= target; j += 1) {
            dp[j] = prev[j];
            if (j >= arr[i - 1])
                dp[j] += prev[j - arr[i - 1]];
        }
        prev = dp;
    }
    return dp[target];
}

int main() {
    long long target, n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    cout << "Enter target sum for subset: ";
    cin >> target;
    vector<long long> arr(n);
    cout << "Enter array elements seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Count of all subsets with given sum is: " << perfectSum(arr, target) << "\n";
    return 0;
}