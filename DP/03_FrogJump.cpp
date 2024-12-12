// https://www.codingninjas.com/studio/problems/frog-jump_3621012
#include <bits/stdc++.h>
using namespace std;
long main()
{
    long n;
    cout << "Enter number of stairs: ";
    cin >> n;
    vector<long> stair(n), dp(n);
    cout << "Enter heights of stairs: ";
    for (long i = 0; i < n; i += 1)
        cin >> stair[i];
    cout << "Min energy to reach n th stair: " << frogJump(n, stair, dp) << "\n";
    return 0;
}
long frogJump(long n, vector<long> &heights, vector<long> &dp)
{
    dp[1] = abs(heights[1] - heights[0]);
    for (long i = 2; i < n; i += 1)
        dp[i] = min(dp[i - 2] + abs(heights[i] - heights[i - 2]), dp[i - 1] + abs(heights[i] - heights[i - 1]));
    return dp[n - 1];
}
// Modification: allowed jumps from 1 and 2 to 1,2,3...k?
// Time complexity: O(nk)
// Space complexity: O(n)
// Space optimized: O(k)