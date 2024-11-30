#include <bits/stdc++.h>
using namespace std;
// Assuming a array of 4 elememts
// Divide the array into two partition with minimum difference in their sum (Almost equal sum partitions).
// - similar to equal sum partition where target is smaller than equal to half of sum of array.
// sum1 + sum2 = sum
// sum1 + sum1 + diff = sum (If sum1 is smaller)
// diff = sum - (2 * sum1)
// sum1 < = sum / 2 

// arr  | 0 1 2 3 4 5 6 7 8 9 10 11 |- sum
//      | - - - - - - - - - - -  -  | n
//      | 1 0 0 0 0 0 0 0 0 0 0  0  | 0
//  1   | 1 1 0 0 0 0 0 0 0 0 0  0  | 1
//  6   | 1 1 0 0 0 0 1 1 0 0 0  0  | 2
//  11  | 1 1 0 0 0 0 1 1 0 0 0  1  | 3
//  5   | 1 1 0 0 0 1 1 1 0 0 0  1  | 4
//      | - - - - - - - - - - -  -  |
bool MinimumPartitionSumDifference(vector<int> arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i += 1)
        sum += arr[i];
    int target = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i += 1) {
    //     for (int j = 0; j <= target; j += 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    for(int j=target;j>=0;j++)
        if(dp[n][j])
            return sum - 2*j;
}
// Time Complexity: O(W*N)
// Space Complexity: O(W*N)

bool MinimumPartitionSumDifferenceOptimized(vector<int> arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i += 1)
        sum += arr[i];
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : arr) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    // for (int i = 0; i <= target; i += 1)
    //     cout << dp[i] << " ";
    for(int j=target;j>=0;j++)
        if(dp[j])
            return sum - 2*j;
}
// Time Complexity: O(W*N)
// Space Complexity: O(W)

int main() {
    int n;
    cout << "Enter number of array elements: ";
    cin >> n;
    cout << "Enter value of array elements: \n";
    vector<int> arr(n);
    for (int i = 0; i < n; i += 1) {
        cin >> arr[i];
    }
    // cout << "MinimumPartitionSumDifference " << " possible: " << MinimumPartitionSumDifference(arr, n) << "\n";
    cout << "MinimumPartitionSumDifference " << " possible: " << MinimumPartitionSumDifferenceOptimized(arr, n) << "\n";
    return 0;
}