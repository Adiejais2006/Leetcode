// Last updated: 7/18/2026, 2:00:06 PM
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {

            if (n % (i + 1) == 0)
                sum += pow(nums[i], 2);
        }

        return sum;
    }
};