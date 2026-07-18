// Last updated: 7/18/2026, 2:07:52 PM
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int prevdiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int start = i + 1;
            int end = n - 1;
            while (start < end) {
                int sum = nums[i] + nums[start] + nums[end];
                int diff = abs(sum - target);
                if (diff < prevdiff) {
                    ans = sum;
                    prevdiff = diff;
                }
                if (sum < target)
                    start++;
                else if (sum>target)
                    end--;
                    else return ans ;
            }
        }
        return ans;
    }
};