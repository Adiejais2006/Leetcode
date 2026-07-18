// Last updated: 7/18/2026, 2:00:26 PM
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int digitsum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (nums[i] > 0) {
                int d = nums[i] % 10;
                digitsum += d;
                nums[i] = nums[i] / 10;
            }
        }
        return abs(sum - digitsum);
    }
};