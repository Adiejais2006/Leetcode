// Last updated: 10/29/2026, 11:36:22 PM
1class Solution {
2public:
3    int arrayPairSum(vector<int>& nums) {
4        int n = nums.size();
5        sort(nums.begin() , nums.end());
6        int ans= 0 ; 
7        int sum = 0 ;
8        for(int i = 0 ; i<n-1 ; i+=2){
9        ans +=nums[i];
10        }
11        return ans ;
12    }
13};