// Last updated: 7/18/2026, 2:07:20 PM
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void solve(vector<int>& nums, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (visited[i])
                continue;
            visited[i] = true;
            temp.push_back(nums[i]);
            solve(nums, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        solve(nums, visited);
        return ans;
    }
};