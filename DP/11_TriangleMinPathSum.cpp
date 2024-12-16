// https://www.codingninjas.com/studio/problems/triangle_1229398
// https://leetcode.com/problems/triangle/description/
#include <bits/stdc++.h> 
using namespace std;
// // DP solution
// long TriangleMinimumPathSum(vector<vector<long>>& grid, long n){
// 	vector<vector<long>> dp(n,vector<long>(n));
// 	for(long i=n-1;i>=0;i-=1){
// 		for(long j=0;j<=i;j+=1){
// 			if(i!=n-1)
// 			dp[i][j]=min(dp[i+1][j],dp[i+1][j+1]);
// 			dp[i][j]+=grid[i][j];
// 		}
// 	}
// 	return dp[0][0];
// }
// Optimized DP solution
long TriangleMinimumPathSum(vector<vector<long>>& grid, long n){
	vector<long> dp(n),prev(n);
	for(long i=n-1;i>=0;i-=1){
		for(long j=0;j<=i;j+=1){
			if(i!=n-1)
			prev[j]=min(dp[j],dp[j+1]);
			prev[j]+=grid[i][j];
		}
		for(long j=0;j<=i;j+=1) dp[j]=prev[j];
	}
	return dp[0];
}

int main()
{
    long n,m,tmp;
    cout << "Enter triangle size: ";
    cin >> n;
    vector<vector<long>> mat(n);
    cout<<"Enter grid values:\n";
    for(long i=0;i<n;i+=1)
    for(long j=0;j<=i;j+=1){
    cin>>tmp;
    mat[i].push_back(tmp);
    }
    cout << "Ways to reach last row from first row going i,j to i+1,j or i+1,j+1: " << TriangleMinimumPathSum(mat,n) << "\n";
    return 0;
}