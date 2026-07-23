// Last updated: 7/24/2026, 12:13:07 AM
1class Solution {
2public:
3    vector<int> buildArray(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>ans(n);
6        for(int i=0;i<n;i++) {
7            ans[i]=nums[nums[i]];
8        }
9        return ans;       
10    }
11};