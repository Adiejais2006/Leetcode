// Last updated: 11/4/2026, 6:13:44 PM
1class Solution {
2public:
3    int maximizeSum(vector<int>& nums, int k) {
4        int ans = 0 ;
5        int maxi = 0 ;
6        for(auto it:nums) maxi=max(maxi,it);
7        while(k>0){
8            ans+=maxi++;
9            k--;
10        }
11        return ans ;
12    }
13};