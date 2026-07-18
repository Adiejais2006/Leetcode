// Last updated: 7/18/2026, 2:08:12 PM
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            int k = target-nums[i];
            if (mpp.find(k) != mpp.end()) {
                ans.push_back(i);
                ans.push_back(mpp[k]);
            }

            mpp[nums[i]] = i;
        }
        return ans;
    }
};