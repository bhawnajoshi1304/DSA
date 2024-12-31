// https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int perfectSum(vector<int>& arr, int target) {
    //     int n=arr.size();
    //     vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    //     dp[0][0]=1;
    //     for(int i=1;i<=n;i+=1){
    //         dp[i][0]=1;
    //         for(int j=0;j<=target;j+=1){
    //             if(j>=arr[i-1])
    //             dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
    //             else
    //             dp[i][j]=dp[i-1][j];
    //         }
    //     }
    //     return dp[n][target];
    // }
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int> dp(target+1,0),prev(target+1,0);
        dp[0]=prev[0]=1;
        for(int i=1;i<=n;i+=1){
            dp[0]=1;
            for(int j=0;j<=target;j+=1){
                dp[j]=prev[j];
                if(j>=arr[i-1])
                dp[j]+=prev[j-arr[i-1]];
            }
            prev = dp;
        }
        return dp[target];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends