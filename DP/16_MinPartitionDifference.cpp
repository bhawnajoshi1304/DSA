// https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
// You are given an array 'arr' containing 'n' non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.

// (Hard version yet to solve) https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/description/

#include<bits/stdc++.h>
using namespace std;
long long minSubsetSumDifference(vector<long long>& arr) {
    long long sum = 0, n = arr.size();
    for (long long i = 0; i < n; i += 1)
        sum += arr[i];
    long long target = sum / 2;
    // vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    // for (long long i = 0; i <= n; ++i)
    //     dp[i][0] = true;
    // for (long long i = 1; i <= n; ++i) {
    //     for (long long j = 1; j <= target; ++j) {
    //         if (arr[i - 1] <= j)
    //             dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
    //         else
    //             dp[i][j] = dp[i - 1][j];
    //     }
    // }
    // for(long long j=target;j>=0;j--){
    //     if(dp[n][j])
    //         return sum - 2*j;}
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (long long num : arr) {
        for (long long j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    for(long long j=target;j>=0;j--)
        if(dp[j])
            return sum - 2*j;
}

int main() {
    long long n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    vector<long long> arr(n);
    cout << "Enter array elements seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Minimmum subset sum difference: " << minSubsetSumDifference(arr) << "\n";
    return 0;
}