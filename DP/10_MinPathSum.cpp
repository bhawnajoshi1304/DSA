// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349

#include <bits/stdc++.h>
using namespace std;

// // DP solution
// int minSumPath(vector<vector<int>> &grid) {
//     int m = grid.size(),n= grid[0].size();
//     vector<vector<int>> dp(m,vector<int> (n,0));
//     for(int i=0;i<m;i+=1){
//         for(int j=0;j<n;j+=1){
//             dp[i][j]+=grid[i][j];
//             if(i>0 && j==0)
//             dp[i][j]+=dp[i-1][j];
//             if(j>0 && i==0) 
//             dp[i][j]+=dp[i][j-1];
//             if(i>0 && j>0)
//             dp[i][j]+=min(dp[i][j-1],dp[i-1][j]);
//         }
//     }
//     return dp[m-1][n-1];
// }
//     return dp[m-1][n-1];
// }
// Space Optimized DP solution
int minSumPath(vector<vector<int>> &grid) {
    int m = grid.size(),n= grid[0].size();
    vector<int> dp(n,0);
    for(int i=0;i<m;i+=1){
        for(int j=0;j<n;j+=1){
            dp[j]+=grid[i][j];
            if(j>0 && i==0) 
                dp[j]+=dp[j-1];
            if(i>0 && j>0)
                dp[j]=min(dp[j-1]+grid[i][j],dp[j]);
        }
    }
    return dp[n-1];
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
    cout << "Ways to reach grid[n-1][m-1] from grid[0][0] going down or right: " << minSumPath(mat) << "\n";
    return 0;
}