// Last updated: 7/18/2026, 2:07:27 PM
class Solution {void func( int sum , int ind, vector<int>&nums , vector<int> &temp , vector<vector<int>> &ans ){
        if(sum==0){
            ans.push_back(temp);
            return;
        }
        if(sum<0) return;
        if(ind==nums.size()){
            return;
        }

        func(sum , ind+1 , nums, temp,ans);
        temp.push_back(nums[ind]);
        func(sum - nums[ind], ind,nums , temp,ans  );
        temp.pop_back();

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        vector<int> temp;
        func(target ,0 , candidates , temp , ans);
        return ans ;
    }
};