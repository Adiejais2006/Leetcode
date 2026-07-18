// Last updated: 7/18/2026, 2:03:00 PM
class Solution {

    int func(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int ans = 0;
        while (r < n) {
            sum = sum + nums[r];
            while (l <= r && sum > goal) {
                sum -= nums[l];
                l++;
            }
            ans += (r - l + 1);
            r++;
        }
        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return func(nums, goal) - func(nums, goal - 1);
    }
};