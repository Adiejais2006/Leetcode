// Last updated: 7/18/2026, 2:06:46 PM
class Solution {  void func(int index, vector<int>& nums, vector<vector<int>>& ans,
              vector<int> temp) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[index]);
        func(index + 1, nums, ans, temp);
        temp.pop_back();
        for (int j = index + 1; j < nums.size(); j++) {
            if (nums[j] !=  nums[index]) {
                func(j  , nums , ans , temp );
                return;
            }
        }

        func(nums.size() , nums , ans , temp );
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        func(0, nums, ans, temp);
        return ans;
    }
};