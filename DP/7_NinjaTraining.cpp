// https://www.codingninjas.com/studio/problems/ninja%E2%80%99s-training_3621003
#include <bits/stdc++.h>
using namespace std;

long ninjaTraining(long n, vector<vector<long>> &arr, vector<vector<long>> &dp)
{
    // for(long i=0;i<n;i+=1){
    //     for(long j=0;j<3;j+=1){
    //         if(i==0) dp[i][j] = arr[i][j];
    //         else{
    //             if(dp[i-1][j]!=dp[i-1][3])
    //                 dp[i][j] = arr[i][j] + dp[i-1][3];
    //             else{
    //                 for(long k=0;k<3;k+=1){
    //                     if(j!=k)
    //                     dp[i][j] = max(dp[i-1][k]+arr[i][j],dp[i][j]);
    //                 }
    //             }
    //         }
    //         dp[i][3]=max(dp[i][3],dp[i][j]);
    //     }
    // }
    // return dp[n-1][3];
    for(long i=0;i<n;i+=1){
        for(long j=0;j<3;j+=1){
            if(i==0) dp[i][j] = arr[i][j];
            else{
                    for(long k=0;k<3;k+=1){
                        if(j!=k)
                        dp[i][j] = max(dp[i-1][k]+arr[i][j],dp[i][j]);
                    }
                }
            }
        }
    long ans= 0;
    for(long i=0;i<3;i+=1){
        ans=max(ans,dp[n-1][i]);
    }
    return ans;
}

// Time complexity: O(n)
// Space complexity: O(n)
// Space optimized: O(1)
int main()
{
    long n;
    cout << "Enter number of days: ";
    cin >> n;
    vector<vector<long>> points(n,vector<long>(3,0));
    cout << "Enter arr of points:\n";
    for (long i = 0; i < n; i += 1)
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    vector<vector<long>> dp(n,vector<long>(3,0));
    cout << "Max points in n days: " << ninjaTraining(n, points, dp) << "\n";
    return 0;
}