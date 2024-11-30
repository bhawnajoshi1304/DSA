#include <bits/stdc++.h>
using namespace std;
// Given an array and a sum count the number of subsets with a given sum.
// Multiple subsets can contain same element
// Assuming a array of 6 elememts and given a sum 10
// Count 3 : [{2,8}, {2,3,5}, {10}]
// arr | 0 1 2 3 4 5 6 7 8 9 10 - sum
//     | - - - - - - - - - - - | n
//     | 1 0 0 0 0 0 0 0 0 0 0 | 0
//  2  | 1 0 1 0 0 0 0 0 0 0 0 | 1
//  3  | 1 0 1 1 0 1 0 0 0 0 0 | 2
//  5  | 1 0 1 1 0 2 0 1 1 0 1 | 3
//  6  | 1 0 1 1 0 2 1 1 2 1 1 | 4
//  8  | 1 0 1 1 0 2 1 1 3 1 2 | 3
//  10 | 1 0 1 1 0 2 1 1 3 1 3 | 4
//     | - - - - - - - - - - - |
int CountSubsetSum(vector<int> arr, int n, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i += 1) {
    //     for (int j = 0; j <= target; j += 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][target];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W*N)

int CountSubsetSumOptimized(vector<int> arr, int n, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int num : arr) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] + dp[j - num];
        }
    }
    // for (int i = 0; i <= target; i += 1)
    //     cout << dp[i] << " ";
    return dp[target];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W)

int main() {
    int n, sum;
    cout << "Enter number of array elements: ";
    cin >> n;
    cout << "Enter value of array elements: \n";
    vector<int> arr(n);
    for (int i = 0; i < n; i += 1) {
        cin >> arr[i];
    }
    cout << "Enter given sum of subsets: ";
    cin >> sum;
    // cout << "CountSubsetSum " << sum << ": " << CountSubsetSum(arr, n, sum) << "\n";
    cout << "CountSubsetSum " << sum << ": " << CountSubsetSumOptimized(arr, n, sum) << "\n";
    return 0;
}