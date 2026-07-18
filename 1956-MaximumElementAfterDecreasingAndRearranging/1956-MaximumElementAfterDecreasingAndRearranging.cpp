// Last updated: 7/18/2026, 2:01:30 PM
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums[0] = 1;
        int i = 1;  int ans = INT_MIN;
        while (i < n) {
            if (abs(nums[i - 1] - nums[i]) <= 1)
                i++;
            else {
                int a = nums[i - 1] + 1;
                nums[i] = a;
                i++;
            }
        }
      
      
        return nums[n-1];
    }
};