// https://www.codingninjas.com/studio/problems/house-robber-ii_839733
// https://leetcode.com/problems/house-robber-ii/
#include <bits/stdc++.h>
using namespace std;
long long solve(vector<long long> nums) {
    long long n = nums.size();
    if (n == 0)
        return 0;
    long long curr = INT_MIN, prev1 = INT_MIN, prev2 = INT_MIN;
    if (n >= 1)
        prev2 = nums[0];
    if (n >= 2)
        prev1 = max(nums[0], nums[1]);
    curr = max(prev1, prev2);
    for (long long i = 2; i < n; i += 1) {
        curr = max(prev1, nums[i] + prev2);
        prev2=prev1;
        prev1=curr;
    }
    return curr;
}
long long solve(vector<long long> nums) {
    long long n = nums.size();
    if (n == 0)
        return 0;
    vector<long long> dp(n);
    if (n >= 1)
        dp[0] = nums[0];
    if (n >= 2)
        dp[1] = max(nums[0], nums[1]);
    for (long long i = 2; i < n; i += 1) {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
    }
    return dp[n - 1];
}
long long houseBreaker(vector<long long>& nums) {
    long long n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    return max(solve(vector<long long>(nums.begin(), nums.end() - 1)), solve(vector<long long>(nums.begin() + 1, nums.end())));
}
// Time complexity: O(n)
// Space complexity: O(n)
// Space optimized: O(1)
int main()
{
    long long n;
    cout << "Enter number of houses: ";
    cin >> n;
    vector<long long> house(n);
    cout << "Enter arr of houses: ";
    for (long long i = 0; i < n; i += 1)
        cin >> house[i];
    cout << "Min energy to reach n th house: " << houseBreaker(house) << "\n";
    return 0;
}