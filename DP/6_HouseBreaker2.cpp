// https://www.codingninjas.com/studio/problems/house-robber-ii_839733
#include <bits/stdc++.h>
using namespace std;

long houseBreaker(long n, vector<long> &arr, vector<long> &dp)
{
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for (long i = 1; i < n; i += 1){
        dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
    }
    return max(dp[n-1],dp[n-2]);
}
long houseBreaker(long n, vector<long> &arr)
{
    if(n==1) return arr[0];
    long prev1 = arr[0], prev2 = max(arr[0],arr[1]),curr=prev2;
    for (long i = 2; i < n; i += 1){
        curr = max(arr[i]+prev1,prev2);
        prev1 = prev2;
        prev2 = curr;
    }
    return max(prev1,prev2);
}
// Time complexity: O(n)
// Space complexity: O(n)
// Space optimized: O(1)
int main()
{
    long n;
    cout << "Enter number of houses: ";
    cin >> n;
    vector<long> house(n);
    cout << "Enter arr of houses: ";
    for (long i = 0; i < n; i += 1)
        cin >> house[i];
    vector<long> dp(n,INT_MAX);
    cout << "Min energy to reach n th house: " << houseBreaker(n, house, dp) << "\n";
    return 0;
}