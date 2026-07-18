// Last updated: 7/18/2026, 1:58:44 PM
class Solution {
    bool leftcheck(int i, vector<int>& nums) {
        for (int j = i - 1; j >= 0; j--) {
            if (nums[i] <= nums[j])
                return false;
        }
        return true;
    }
    bool rightCheck(int i, vector<int>& nums) {

        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] <= nums[j])
                return false;
        }
        return true;
    }

public:
    vector<int> findValidElements(vector<int>& nums) {
        if(nums.size()==1) return {nums[0]};
        int n = nums.size();
        vector<int>ans;
        ans.push_back(nums[0]);
        for (int i = 1; i < n - 1; i++) {
            if (leftcheck(i, nums) || rightCheck(i,nums)){
                ans.push_back(nums[i]);
            }
        }
        ans.push_back(nums[n-1]);
        return ans ;
    }
};