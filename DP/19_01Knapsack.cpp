// https://www.naukri.com/code360/problems/0-1-knapsack_920542
#include <bits/stdc++.h>
using namespace std;
// wt val  | 0 1 2 3 4 5 6 7 - w
//         | - - - - - - - - | n
//         | 0 0 0 0 0 0 0 0 | 0
//  1   1  | 0 1 1 1 1 1 1 1 | 1
//  3   4  | 0 1 1 4 5 5 5 5 | 2
//  4   5  | 0 1 1 4 5 6 6 9 | 3
//  5   7  | 0 1 1 4 5 7 8 9 | 4
//         | - - - - - - - - |
long long knapsack(vector<long long> &wt, vector<long long> &val, long long capacity, long long n) {
    // if n is 0 or capcity is 0 ans will be 0
    // taking 1 item at a time
    // if item i is more than capacity -> do not take it
    // if item is within limit we take it or take maximum value till now


    // if(n==0 || capacity==0) return 0;
    // if(wt[n-1]<=capacity) return max(val[n-1]+knapsack(wt,val,capacity-wt[n-1],n-1),knapsack(wt,val,capacity,n-1));
    // return knapsack(wt,val,capacity,n-1);

    // vector<vector<long long>> dp(n+1,vector<long long>(capacity+1,0));
    // for(int i=1;i<=n;i+=1){
    //     for(int j=1;j<=capacity;j+=1){
    //         if(j>=wt[i-1])
    //         dp[i][j] = max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
    //         else
    //         dp[i][j] = dp[i-1][j];
    //     }
    // }
    // return dp[n][capacity];

    // vector<long long> prev(capacity+1), curr(capacity+1);
    // for(int i=1;i<=n;i+=1){
    //     for(int j=1;j<=capacity;j+=1){
    //         if(j>=wt[i-1]){
    //             curr[j] = max(prev[j],prev[j-wt[i-1]]+val[i-1]);
    //         }
    //         else 
    //         curr[j]= prev[j];
    //     }
    //     prev=curr;
    // }
    // return curr[capacity];

    vector<long long> dp(capacity+1);
    for(int i=1;i<=n;i+=1){
        for(int j=capacity;j>=0;j-=1){
            if(j>=wt[i-1])
            dp[j]=max(dp[j],dp[j-wt[i-1]+val[i-1]]);
        }
    }
    return dp[capacity];
}
int main() {
    long long capacity, n;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;
    vector<long long> wt(n), val(n);
    cout << "Enter the weights of items seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> wt[i];
    cout << "Enter the value of items seperated by space: ";
    for (long long i = 0; i < n; i++)
        cin >> val[i];
    cout << "Knapsack total value: " << knapsack(wt, val, capacity, n) << "\n";
    return 0;
}