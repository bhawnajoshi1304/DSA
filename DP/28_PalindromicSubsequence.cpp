class Solution {
public:
// https://leetcode.com/problems/longest-palindromic-subsequence/
    int longestPalindromeSubseq(string s) {
        // LCS with reverse
        //   b b b a b
        // b 1 1 1 0 1
        // a 0 2 2 2 0
        // b 1 1 3 0 3
        // b 1 2 2 0 1
        // b 1 2 3 0 1
        int n=s.size();
        // vector<vector<int>> dp(n,vector<int>(n,0));
        // for(int i=0;i<n;i+=1){
        //     for(int j=0;j<n;j+=1){
        //         if(s[i] == s[n-1-j]){
        //             dp[i][j]=(i==0 || j==0)?1:dp[i-1][j-1]+1;
        //         }
        //         else{
        //             dp[i][j]=max((i>0)?dp[i-1][j]:0,(j>0)?dp[i][j-1]:0);
        //         }
        //     }
        // }
        // return dp[n-1][n-1];

        int prevRow,prevRowCol;
        vector<int> dp(n,0);
        for(int i=0;i<n;i+=1){
            for(int j=0;j<n;j+=1){
                prevRow = dp[j];
                if(s[i] == s[n-1-j]){
                    dp[j]=(i==0 || j==0)?1:prevRowCol+1;
                }
                else{
                    dp[j]=max((i>0)?prevRow:0,(j>0)?dp[j-1]:0);
                }
                prevRowCol=prevRow;
            }
        }
        return dp[n-1];
    }
};