// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
        // vector<vector<int>> dp(n+1,vector<int>(capacity+1));
        // for(int i=1;i<=n;i+=1){
        //     for(int j=1;j<=capacity;j+=1){
        //         if(j>=wt[i-1])
        //         dp[i][j]=max(dp[i][j-wt[i-1]]+val[i-1],dp[i-1][j]);
        //         else
        //         dp[i][j]=dp[i-1][j];
        //     }
        // }
        // return dp[n][capacity];
        
        vector<int> dp(capacity+1);
        for(int i=1;i<=n;i+=1){
            for(int j=1;j<=capacity;j+=1){
                if(j>=wt[i-1])
                dp[j]=max(dp[j-wt[i-1]]+val[i-1],dp[j]);
            }
        }
        return dp[capacity];
    }
};