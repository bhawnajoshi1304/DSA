// https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        //     a c e
        //   0 0 0 0   
        // a 0 1 1 1 
        // b 0 1 1 1
        // c 0 1 2 2
        // d 0 1 2 2
        // e 0 1 2 3
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // for(int i=1;i<=n;i+=1){
        //     for(int j=1;j<=m;j+=1){
        //         if(text1[i-1] == text2[j-1]){
        //             dp[i][j]=dp[i-1][j-1]+1;
        //         }
        //         else
        //             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        //     }
        // }
        // return dp[n][m];
        vector<int> dp(m+1);
        for(int i=1;i<=n;i+=1){
            int prevRow = 0, prevRowPrevCol = 0;
            for(int j=1;j<=m;j+=1){
                prevRowPrevCol = prevRow;
                prevRow = dp[j];
                if(text1[i-1] == text2[j-1]){
                    dp[j]=prevRowPrevCol+1;
                }
                else
                    dp[j]=max(dp[j-1],prevRow);
            }
        }
        return dp[m];
    }
};