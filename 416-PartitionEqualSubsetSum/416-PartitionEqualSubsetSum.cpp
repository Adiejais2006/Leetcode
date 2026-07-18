// Last updated: 7/18/2026, 2:04:38 PM
class Solution {

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        if (sum % 2 == 1)
            return false;
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        if (nums[0] <= sum/2)
            dp[0][nums[0]] = true;

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= sum / 2; target++) {
                bool pick = false;
                if (nums[ind] <= target)
                    pick = dp[ind - 1][target - nums[ind]];
                bool notpick = dp[ind - 1][target];
                dp[ind][target] = pick || notpick;
            }
        }

        return dp[n - 1][sum / 2];
    }
};