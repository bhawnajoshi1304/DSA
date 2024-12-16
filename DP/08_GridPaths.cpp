// https://leetcode.com/problems/unique-paths/
// https://www.codingninjas.com/studio/problems/unique-paths_1081470

#include <bits/stdc++.h>
using namespace std;
//Optimized combinatorics solution
    int uniquePaths(int m, int n) {
        long long x=1,y=min(m,n),z=max(m,n);
        for(int i=z;i<z+y-1;i++)
            x*=i;
        // (m+n-1)! / m!n!
        for(int i=2;i<y;i++)
            x/=i;
        return x;
        
    }
// // Space optimized DP solution 
// int uniquePaths(int m, int n) {
//     vector<int> dp(n);
//     dp[0]=1;
//     for(int i=0;i<m;i+=1)
//         for(int j=0;j<n;j+=1)
//             if(j-1>=0)
//                 dp[j] += dp[j-1];
//     return dp[n-1];
// }
// // DP solution
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> grid(m, vector<int>(n));
//         grid[m - 1][0] = 1;
//         int i, j;
//         for(i = m - 1; i > -1; --i)
//             for(j = 0; j < n; ++j)
//                 if(j > 0)
//                     grid[i][j] += grid[i][j - 1];
//                 if(i < m - 1)
//                     grid[i][j] += grid[i + 1][j];
//         return grid[0][n - 1];
//     }
// // Memorized solution
// int fun(vector<vector<int>> &dp, int i, int j, int m, int n){
//     if(i==m-1 && j==n-1)
//         return 1;
//     else if(i>=m || j>=n)
//         return 0;
//     else if(dp[i][j]==0){
//         dp[i][j]=fun(dp,i+1,j,m,n)+fun(dp,i,j+1,m,n);
//         return dp[i][j];
//     }
//     else
//         return dp[i][j];
// }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m,vector<int>(n));
//         return fun(dp,0,0,m,n);
//     }

int main()
{
    long n,m;
    cout << "Enter grid size: ";
    cin >> n >> m;
    cout << "Ways to reach grid[n-1][m-1] from grid[0][0] going down or right: " << uniquePaths(m,n) << "\n";
    return 0;
}