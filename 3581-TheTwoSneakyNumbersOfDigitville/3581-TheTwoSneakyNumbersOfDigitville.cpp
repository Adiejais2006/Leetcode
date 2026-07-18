// Last updated: 7/18/2026, 1:59:39 PM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
            mpp[nums[i]]++;

        for (auto it : mpp) {
            if (it.second > 1) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};