// https://www.codingninjas.com/studio/problems/minimal-cost_8180930
// Modification: allowed jumps from 1 and 2 to 1,2,3...k?
#include <bits/stdc++.h>
using namespace std;

long frogJump(long n, long k, vector<long> &heights, vector<long> &dp)
{
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for (long i = 1; i < n; i += 1){
        for (long j = 1; j <= k; j += 1){
          if (i >= j) {
            dp[i] = min(dp[i-j] + abs(heights[i]-heights[i-j]),dp[i]);
          }
        }
    }
    return dp[n - 1];
}
// Time complexity: O(nk)
// Space complexity: O(n)
// Space optimized: O(k)
int main()
{
    long n,k;
    cout << "Enter number of stairs: ";
    cin >> n;
    vector<long> stair(n);
    cout << "Enter heights of stairs: ";
    for (long i = 0; i < n; i += 1)
        cin >> stair[i];
    cout << "Enter maximum height jump: ";
    cin >> k;
    vector<long> dp(n,INT_MAX);
    cout << "Min energy to reach n th stair: " << frogJump(n, k, stair, dp) << "\n";
    return 0;
}