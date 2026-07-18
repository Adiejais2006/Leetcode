// Last updated: 7/18/2026, 2:08:00 PM
class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int ans = 0;
        while (l < r) {
            int side = min(nums[l], nums[r]);
            ans = max(ans, side * (r - l));
            if (nums[l] < nums[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};