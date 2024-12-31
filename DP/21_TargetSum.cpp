// https://leetcode.com/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // partition sum difference problem
        // sum1-sum2 = target
        // sum1+sum2 = sum
        // sum1 = (target+sum)/2
        // number of ways to have sum sum1
        int sum1, sum = 0, n = nums.size();
        for (auto i : nums) {
            sum += i;
        }
        sum1 = (target + sum) / 2;
        if ((target + sum) != 2 * sum1 || sum1 < 0)
            return 0;
        // vector<vector<int>> dp(n + 1, vector<int>(sum1 + 1, 0));
        // dp[0][0] = 1;
        // for (int i = 1; i <= n; i += 1) {
        //     for (int j = 0; j <= sum1; j += 1) {
        //         if (j >= nums[i - 1])
        //             dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        //         else
        //             dp[i][j] = dp[i - 1][j];
        //     }
        // }
        // return dp[n][sum1];
        vector<int> dp(sum1 + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i += 1) {
            for (int j = sum1; j >= nums[i - 1]; j -= 1) {
                dp[j] = dp[j] + dp[j - nums[i - 1]];
            }
        }
        return dp[sum1];
    }
};