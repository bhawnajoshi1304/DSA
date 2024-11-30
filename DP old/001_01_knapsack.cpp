#include <bits/stdc++.h>
using namespace std;
int KnapsackRecursive(vector<int> &wt, vector<int> &val, int n, int capacity) {
    if (n == 0 || capacity == 0)
        return 0;
    if (wt[n - 1] > capacity)
        return KnapsackRecursive(wt, val, n - 1, capacity);

    return max(val[n - 1] + KnapsackRecursive(wt, val, n - 1, capacity - wt[n - 1]), KnapsackRecursive(wt, val, capacity, n - 1));
}

vector<vector<int>> t(1001, vector<int>( 10001, -1));
int KnapsackMemorised(vector<int> &wt, vector<int> &val, int n, int capacity) {
    if (n == 0 || capacity == 0)
        return 0;
    if (t[n][capacity] != -1) return t[n][capacity];
    if (wt[n - 1] > capacity)
        return t[n][capacity] = KnapsackMemorised(wt, val, n - 1, capacity);
    
    return max(val[n - 1] + KnapsackMemorised(wt, val, n - 1, capacity - wt[n - 1]), KnapsackMemorised(wt, val, capacity, n - 1));
}

// Assuming a knapsack with capacity 7 and 4 different weights available.
// The maximum value of knapsack is 9
// wt val  | 0 1 2 3 4 5 6 7 - w
//         | - - - - - - - - | n
//         | 0 0 0 0 0 0 0 0 | 0
//  1   1  | 0 1 1 1 1 1 1 1 | 1
//  3   4  | 0 1 1 4 5 5 5 5 | 2
//  4   5  | 0 1 1 4 5 6 6 9 | 3
//  5   7  | 0 1 1 4 5 7 8 9 | 4
//         | - - - - - - - - |
int Knapsack01(vector<int> &wt, vector<int> &val, int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (wt[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    // for (int i = 0; i <= n; i += 1) {
    //     for (int j = 0; j <= capacity; j += 1)
    //         cout << dp[i][j] << " ";
    //     cout << "\n";
    // }
    return dp[n][capacity];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W*N)

int Knapsack01Optimized(vector<int> &wt, vector<int> val, int n, int capacity) {
    vector<int> dp(capacity + 1, 0);
    for (int i = 0; i < wt.size(); ++i) {
        for (int j = capacity; j >= wt[i]; --j)
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
    }
    // for (int i = 0; i <= capacity; i += 1)
    //     cout << dp[i] << " ";
    return dp[capacity];
}
// Time Complexity: O(W*N)
// Space Complexity: O(W)

int main() {
    int n, w;
    cout << "Enter number of weights: ";
    cin >> n;
    cout << "Enter weights for each weight: \n";
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i += 1) {
        cin >> wt[i];
    }
    cout << "Enter value for each weight: \n";
    for (int i = 0; i < n; i += 1) {
        cin >> val[i];
    }
    cout << "Enter capacity of knapsack: ";
    cin >> w;
    // cout<<"Maximum value knapsack is: "<<Knapsack01(wt,val,n,w)<<"\n";
    cout << "Maximum value knapsack is: " << Knapsack01Optimized(wt, val, n, w) << "\n";
    return 0;
}