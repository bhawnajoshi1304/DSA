// https://leetcode.com/problems/wildcard-matching/description/
class Solution {
public:
    bool isMatch(string s, string p) {
        // adceb *a*b 

        //     a * b * c ? z
        //   1 0 0 0 0 0 0 0
        // a 0 1 1 0 0 0 0 0
        // b 0 0 1 1 1 0 0 0
        // b 0 0 1 1 1 0 0 0
        // b 0 0 1 1 1 0 0 0
        // d 0 0 1 1 1 0 0 0
        // c 0 0 1 1 1 1 0 0
        // t 0 0 1 1 1 0 1 0
        // z 0 0 1 1 1 0 0 1

        // vector<vector<bool>> dp(s.size() + 1, vector(p.size() + 1, false));
        // dp[0][0] = true;
        // for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
        //     dp[0][j + 1] = true;
        // }
        // for (int i = 1; i <= s.size(); ++i) {
        //     for (int j = 1; j <= p.size(); ++j) {
        //         if (p[j - 1] == '*') {
        //             dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        //         } else {
        //             dp[i][j] = ((s[i - 1] == p[j - 1]) || (p[j - 1] == '?')) && dp[i - 1][j - 1];
        //         }
        //     }
        // }
        // return dp[s.size()][p.size()];

        vector<bool> dp(p.size()+1,false);
        dp[0]=true;
        for (int j = 0; j < p.size() && p[j] == '*'; ++j) {
            dp[j + 1] = true;
        }
        bool prevRowCol=dp[0],prevRow; // dp[i-1][j-1] for 1 1 -> 0 0
        for(int i=1;i<=s.size();i+=1){
            prevRowCol=dp[0]; // dp[i-1][j] for 1 j -> 0 j
            dp[0] = false; // for i>0 it is 0
            for(int j=1;j<=p.size();j+=1){
                prevRow=dp[j]; // dp[i-1][j] -> previously stored value
                if(p[j-1]=='*'){
                    dp[j]=dp[j-1] || prevRow;
                }else{
                    dp[j] =((s[i-1]==p[j-1])||(p[j-1] == '?')) && prevRowCol;
                }
                prevRowCol=prevRow; // dp[i-1][j] becomes dp[i-1][j-1] if j is increased
            }
        }
        return dp[p.size()];
    }
};