// Last updated: 7/18/2026, 1:58:57 PM
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int maxi = 0;
        int mini = 0;
        for (int i = 0; i < k; i++) {
            mini += nums[i];
            maxi += nums[n - i - 1];
        }

        return abs(maxi - mini);
    }
};