// Last updated: 7/18/2026, 2:05:54 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
          int maxi = INT_MIN;
        int pre = 1;
        int suff = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;
             pre =pre* nums[i];
             suff = suff* nums[n - 1 - i];
            maxi = (long long)max(maxi, max(pre,suff));
        }

        return maxi;
    }
};