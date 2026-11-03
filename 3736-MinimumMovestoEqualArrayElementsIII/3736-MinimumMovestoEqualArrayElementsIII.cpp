// Last updated: 11/3/2026, 12:02:57 PM
1class Solution {
2public:
3    int minMoves(vector<int>& nums) {
4        int n = nums.size();
5        int ans = 0 ;   
6        int maxi =-1;
7        for(auto it:nums){
8            maxi=max(maxi,it);
9        }
10        for(auto it:nums){
11            ans+= abs(maxi-it);
12        }
13        return ans ;
14    }
15};