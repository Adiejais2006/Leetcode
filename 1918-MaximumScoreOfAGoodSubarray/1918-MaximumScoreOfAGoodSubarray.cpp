// Last updated: 7/18/2026, 2:01:31 PM
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        int l = k, r = k;
        int mn = nums[k];
        int ans = nums[k];

        while (l > 0 || r < n - 1) {
            if (l == 0) {
                r++;
            } else if (r == n - 1) {
                l--;
            } else if (nums[l - 1] > nums[r + 1]) {
                l--;
            } else {
                r++;
            }

            mn = min(mn, min(nums[l], nums[r]));
            ans = max(ans, mn * (r - l + 1));
        }

        return ans;
    }
};