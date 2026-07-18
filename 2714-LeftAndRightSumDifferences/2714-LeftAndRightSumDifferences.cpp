// Last updated: 7/18/2026, 2:00:20 PM
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left = 0;
        int right = accumulate(nums.begin(), nums.end(), 0);

        vector<int> ans;
        for (int x : nums) {
            right -= x;
            ans.push_back(abs(left - right));
            left += x;
        }

        return ans;
    }
};