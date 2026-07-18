// Last updated: 7/18/2026, 2:05:49 PM
    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            int left = 0;
            int right = n - 1;

            while (left <= right) {
                int sum = nums[left] + nums[right];
                if (sum == target)
                    break;
                else if (sum > target)
                    right--;
                else
                    left++;
            }
            return {left+1, right+1};
        }
    };