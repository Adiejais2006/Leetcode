// Last updated: 7/18/2026, 2:02:42 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int n = nums.size();
        int ans = 0;
        int ones = 0;
        while (r < n) {
            if (nums[r] == 1)
                ones += 1;
            while (r - l + 1 - ones > k) {
                if (nums[l] == 1)
                    ones -= 1;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};