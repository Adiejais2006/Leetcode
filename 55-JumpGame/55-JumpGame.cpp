// Last updated: 7/18/2026, 2:07:12 PM
class Solution {
public:
    bool canJump(vector<int>& nums) {
         int maxIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIndex) {
                return false;
            }
            maxIndex = max(maxIndex, i + nums[i]);
        }
        return true;
    }
};