//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
// https://www.geeksforgeeks.org/problems/rod-cutting0840/1
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n=price.size();
        // vector<vector<int>> dp(n+1,vector<int>(n+1));
        // for(int i=1;i<=n;i+=1){
        //     for(int j=1;j<=n;j+=1){
        //         if(j>=i)
        //         dp[i][j]=max(dp[i-1][j],dp[i][j-i]+price[i-1]);
        //         else
        //         dp[i][j]=dp[i-1][j];
        //     }
        // }
        // return dp[n][n];
        vector<int> dp(n+1);
        for(int i=1;i<=n;i+=1){
            for(int j=1;j<=n;j+=1){
                if(j>=i)
                dp[j]=max(dp[j],dp[j-i]+price[i-1]);
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends