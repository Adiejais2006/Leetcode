// Last updated: 7/18/2026, 2:03:48 PM
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }

                    else if (dp[i] == dp[j] + 1)
                        count[i] += count[j];
                }
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi)
                cnt += count[i];
        }
        return cnt;
    }
};