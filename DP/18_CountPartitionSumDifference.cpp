// https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        // sum = sum1+sum2
        // sum = sum1 + sum1+ d
        // sum1 = (sum-d)/2
        int n=arr.size(), sum=0;
        for(auto i:arr){
            sum+=i;
        }
        int target = (sum-d);
        if(target<0 || target%2!=0) return 0;
        else
        target/=2;
        // vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        // dp[0][0]=1;
        // for(int i=1;i<=n;i+=1){
        //     for(int j=0;j<=target;j+=1){
        //         if(j>=arr[i-1])
        //         dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
        //         else
        //         dp[i][j]=dp[i-1][j];
        //     }
        // }
        // return dp[n][target];
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
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends