// https://leetcode.com/problems/minimum-falling-path-sum/
#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> prev(n, INT_MAX), curr(n, INT_MAX);
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (i == 0)
                    curr[j] = prev[j] = matrix[i][j];
                else {
                    curr[j] = prev[j] + matrix[i][j];
                    if (i > 0 && j > 0)
                        curr[j] = min(prev[j - 1] + matrix[i][j], curr[j]);
                    if (i > 0 && j + 1 < n)
                        curr[j] = min(prev[j + 1] + matrix[i][j], curr[j]);
                }
            }
            for (int j = 0; j < n; j += 1)
                prev[j]=curr[j];
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j += 1) {
            ans = min(ans, curr[j]);
        }
        return ans;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i += 1) {
            for (int j = 0; j < n; j += 1) {
                if (i == 0)
                    dp[i][j] = matrix[i][j];
                else {
                    dp[i][j] = min(dp[i - 1][j] + matrix[i][j], dp[i][j]);
                    if (j > 0)
                        dp[i][j] = min(dp[i - 1][j - 1] + matrix[i][j], dp[i][j]);
                    if (j + 1 < n)
                        dp[i][j] = min(dp[i - 1][j + 1] + matrix[i][j], dp[i][j]);
                }
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j += 1) {
            ans = min(ans, dp[m - 1][j]);
        }
        return ans;
    }
    
int main()
{
    long n,m;
    cout << "Enter grid size: ";
    cin >> m >> n;
    vector<vector<int>> mat(m,vector<int>(n,0));
    cout<<"Enter grid values:\n";
    for(int i=0;i<m;i+=1)
        for(int j=0;j<n;j+=1)
            cin>>mat[i][j];
    cout << "Min sum to reach grid[n-1] from grid[0] going down or diagonally left/right: " << minFallingPathSum(mat) << "\n";
    return 0;
}