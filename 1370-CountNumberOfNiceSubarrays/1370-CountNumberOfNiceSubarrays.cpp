// Last updated: 7/18/2026, 2:02:12 PM
class Solution {
    int func(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int cnt = 0;
        int n = nums.size();
        while (r < n) {
            if (nums[r] % 2 == 1)
                cnt++;

            while (l <= r && cnt > k) {
                if (nums[l] % 2 == 1) {
                    cnt--;
                }
                l++;
            }

            ans += r - l + 1;
            r++;
        }

        return ans;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k - 1);
    }
};