// Last updated: 7/18/2026, 2:06:56 PM
class Solution { void func(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
              int ind, int end) {
        if (ind == end) {
            ans.push_back(temp);
            return;
        }
        func(nums, ans, temp, ind + 1, end);
        temp.push_back(nums[ind]);
        func(nums, ans, temp, ind + 1, end);
        temp.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>> ans;
        vector<int> temp;
        func(nums, ans, temp, 0, nums.size());
        return ans;
    }
};