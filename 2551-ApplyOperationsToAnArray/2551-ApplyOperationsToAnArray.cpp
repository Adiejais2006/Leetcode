// Last updated: 7/18/2026, 2:00:37 PM
class Solution {
    void func(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j++]);
            }
        }
    }

public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int op = n - 2;
        if (op == 0) {
            func(nums);
            return nums;
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        func(nums);
        return nums;
    }
};