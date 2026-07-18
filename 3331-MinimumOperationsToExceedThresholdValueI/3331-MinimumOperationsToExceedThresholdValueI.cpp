// Last updated: 7/18/2026, 1:59:49 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k)
                cnt++;
        }
        return cnt;
    }
};