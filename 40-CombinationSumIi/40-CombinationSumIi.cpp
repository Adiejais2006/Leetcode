// Last updated: 7/18/2026, 2:07:26 PM
class Solution {  void func(int ind, int sum, vector<int>& nums, vector<int>& temp,
              vector<vector<int>>& ans) {
        if (sum == 0) {
            ans.push_back(temp);
            return;
        }
        if (ind == nums.size() || sum < 0) return;

        // NOT PICK (skip all duplicates)
        int next = ind + 1;
        while (next < nums.size() && nums[next] == nums[ind]) next++;
        func(next, sum, nums, temp, ans);
        // PICK
        temp.push_back(nums[ind]);
        func(ind + 1, sum - nums[ind], nums, temp, ans);
        temp.pop_back();

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
          sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(0, target, candidates, temp, ans);
        return ans;
    }
};