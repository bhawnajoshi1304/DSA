// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
// Given an array arr, partition it into two subsets(possibly empty) such that each element must belong to only one subset. Given a difference d, count the number of partitions with the difference equal to d.
#include <bits/stdc++.h>
using namespace std;
long long countPartitions(vector<long long> &arr, long long d) {
    // sum = sum1+sum2
    // sum = sum1 + sum1+ d
    // sum1 = (sum-d)/2
    long long n = arr.size(), sum = 0;
    for (auto i : arr)
        sum += i;
    long long target = (sum - d);
    if (target < 0 || target % 2 != 0)
        return 0;
    else
        target /= 2;
    // vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
    // dp[0][0] = 1;
    // for (long long i = 1; i <= n; i += 1) {
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
    long long d, n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    cout << "Enter absolute difference of partition: ";
    cin >> d;
    vector<long long> arr(n);
    cout << "Enter array elements seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Number of partitions with given difference are: " << countPartitions(arr, d) << "\n";
    return 0;
}