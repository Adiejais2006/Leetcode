// Last updated: 7/18/2026, 2:05:48 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = nums[0];
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == x) {
                cnt++;
            } else
                cnt--;

            if (cnt < 0) {
                cnt = 0;
                x = nums[i];
            }
        }
        return x;
    }
};