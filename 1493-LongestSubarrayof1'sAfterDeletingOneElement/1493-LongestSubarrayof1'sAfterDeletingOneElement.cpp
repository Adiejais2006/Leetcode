// Last updated: 7/20/2026, 12:09:00 AM
1class Solution {
2public:
3    int longestSubarray(vector<int>& nums) {
4        int l = 0 ; 
5        int r = 0 ;
6        int n = nums.size();
7        int ans = 0 ;
8        int zeroes  =  0 ;
9        while(r<n){
10            if(nums[r]==0) zeroes++;
11            while(zeroes>1){
12                if(nums[l]==0)zeroes--;
13                l++;
14            }
15            int len = r - l + 1 ;
16            int adjlen = len - 1 ;
17            ans=max(ans , adjlen);
18            r++;
19        }
20        return ans ;
21    }
22};