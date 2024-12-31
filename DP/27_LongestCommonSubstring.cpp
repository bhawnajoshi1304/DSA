
//   https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
    int longestCommonSubstr(string& s1, string& s2) {
        //   a b c d g h
        // a 1 0 0 0 0 0 
        // c 0 0 1 0 0 0
        // d 0 0 0 2 0 0 
        // g 0 0 0 0 3 0
        // h 0 0 0 0 0 4
        // r 0 0 0 0 0 0
        // int ans=0,n=s1.size(),m=s2.size();
        // vector<vector<int>> dp(n,vector<int>(m,0));
        // for(int i=0;i<n;i+=1){
        //     for(int j=0;j<m;j+=1){
        //         if(s1[i]==s2[j])
        //             dp[i][j]=(i==0 || j==0)?1:dp[i-1][j-1]+1;
        //         else
        //             dp[i][j]=0;
        //         ans=max(ans,dp[i][j]);
        //     }
        // }
        // return ans;
        
        int ans=0,n=s1.size(),m=s2.size(),prevRowCol,prevRow;
        vector<int> dp(m,0);
        for(int i=0;i<n;i+=1){
            for(int j=0;j<m;j+=1){
                prevRow = dp[j];
                if(s1[i]==s2[j])
                    dp[j]=(i==0 || j==0)?1:prevRowCol+1;
                else
                    dp[j]=0;
                prevRowCol = prevRow;
                ans=max(ans,dp[j]);
            }
        }
        return ans;
    }