// https://www.codingninjas.com/studio/problems/unique-paths-ii_977241

#include <bits/stdc++.h>
using namespace std;

// // DP solution
// int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
//     int mod= 1e9+7;
//     vector<vector<int>> dp(m,vector<int>(n,0));
//     dp[0][0]=1;
//     for(int i=0;i<m;i+=1){
//         for(int j=0;j<n;j+=1){
//             if(mat[i][j]!=-1){
//                 if(i-1>=0)
//                 dp[i][j]+=dp[i-1][j]%mod;
//                 if(j-1>=0)
//                 dp[i][j]+=dp[i][j-1]%mod;
//                 dp[i][j]%=mod;
//             }
//         }
//     }
//     return dp[m-1][n-1];
// }
// Space Optimized DP solution
int mazeObstacles(int m, int n, vector< vector< int> > &mat) {
    int mod= 1e9+7;
    vector<int> dp(n,0);
    dp[0]=1;
    for(int i=0;i<m;i+=1){
        for(int j=0;j<n;j+=1){
            if(mat[i][j]!=-1){
                if(j-1>=0)
                dp[j]+=dp[j-1]%mod;
                dp[j]%=mod;
            }else
            dp[j]=0;
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
    cout<<"Enter grid values(-1 for obstacle, 0 for no obstacle)\n";
    for(int i=0;i<m;i+=1)
    for(int j=0;j<n;j+=1)
    cin>>mat[i][j];
    cout << "Ways to reach grid[n-1][m-1] from grid[0][0] going down or right: " << mazeObstacles(m,n,mat) << "\n";
    return 0;
}