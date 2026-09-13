// Last updated: 9/13/2026, 3:04:49 PM
1class Solution {
2public:
3    vector<int> findDuplicates(vector<int>& nums) {
4        if(nums.empty())return {};
5        vector<int>ans;
6        for(int i=0;i<nums.size();i++){
7            if(nums[abs(nums[i])-1]<0)
8                ans.push_back(abs(nums[i]));
9            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
10        }
11        return ans;
12    }
13};