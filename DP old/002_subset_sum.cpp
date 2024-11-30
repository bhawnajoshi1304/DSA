#include <bits/stdc++.h>
using namespace std;
// Assuming a array of 4 elememts and given a sum 7 
// Is it possible to generate the sum from subset of elements from array.
// Target sum is 9
// arr | 0 1 2 3 4 5 6 7 8 9 - sum
//     | - - - - - - - - - - | n
//     | 1 0 0 0 0 0 0 0 0 0 | 0
//  1  | 1 1 0 0 0 0 0 0 0 0 | 1
//  4  | 1 1 0 0 1 1 0 0 0 0 | 2
//  5  | 1 1 0 0 1 1 1 0 0 1 | 3
//  7  | 1 1 0 0 1 1 1 1 1 1 | 4
//     | - - - - - - - - - - |
bool SubsetSum(vector<int> arr, int n, int target)
{
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
    return dp[n][target];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W*N)

bool SubsetSumOptimized(vector<int> arr, int n, int target) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : arr) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
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
    // cout << "SubsetSum " << sum << " possible: " << SubsetSum(arr, n, sum) << "\n";
    cout << "SubsetSum " << sum << " possible: " << SubsetSumOptimized(arr, n, sum) << "\n";
    return 0;
}