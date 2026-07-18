// Last updated: 7/18/2026, 2:06:08 PM
class Solution {
public:
    int candy(vector<int>& nums) {
           int sum = 1;
        int i = 1 ;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == nums[i - 1]) {
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while (i < n && nums[i] > nums[i - 1]) {
                peak++;
                sum = sum + peak;
                i++;
            }
            int down = 1;
            while (i < n && nums[i] < nums[i - 1]) {
                sum = sum + down;
                down++;
                i++;
            }
            if (down > peak) sum = sum + down - peak;
        }
        return sum;
    }
};