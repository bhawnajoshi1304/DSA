#include <bits/stdc++.h>
using namespace std;
// Assuming a array of 4 elememts
// Count the number of partitions with given difference in the sums.
// - similar to count of subset sum
// sum1 + sum2 = sum
// sum1 + sum1 + diff = sum (If sum1 is smaller)
// sum1 = (sum - diff) / 2 
// 3: [{1,1,2}{3}], [{1,3}{1,2}], [{1,3}{1,2}]
// arr  | 0 1 2 3 |- sum
//      | - - - - | n
//      | 1 0 0 0 | 0
//  1   | 1 1 0 0 | 1
//  1   | 1 2 1 0 | 2
//  2   | 1 2 2 2 | 3
//  3   | 1 2 2 3 | 4
//      | - - - - |
int CountPartitionSumDifference(vector<int> arr, int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i += 1)
        sum += arr[i];
    int target = (sum - diff) / 2;
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

int CountPartitionSumDifferenceOptimized(vector<int> arr, int n, int diff) {
    int sum = 0;
    for (int i = 0; i < n; i += 1)
        sum += arr[i];
    int target = (sum - diff) / 2;
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
    int n, diff;
    cout << "Enter number of array elements: ";
    cin >> n;
    cout << "Enter value of array elements: \n";
    vector<int> arr(n);
    for (int i = 0; i < n; i += 1) {
        cin >> arr[i];
    }
    cout << "Enter given diff of partitions: ";
    cin >> diff;
    // cout << "CountPartitionSumDifference " << ": " << CountPartitionSumDifference(arr, n, diff) << "\n";
    cout << "CountPartitionSumDifference " << ": " << CountPartitionSumDifferenceOptimized(arr, n, diff) << "\n";
    return 0;
}