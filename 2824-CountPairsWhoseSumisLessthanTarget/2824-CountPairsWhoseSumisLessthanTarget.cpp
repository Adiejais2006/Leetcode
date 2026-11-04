// Last updated: 11/4/2026, 2:43:41 PM
1class Solution {
2public:
3    int countPairs(vector<int>& nums, int target) {
4        int n=nums.size(),ans=0;
5        for(int i=0;i<n;i++){
6            for(int j=i+1;j<n;j++){
7                if(nums[i]+nums[j]<target) ans++;
8            }
9        }
10        return ans;
11    }
12};