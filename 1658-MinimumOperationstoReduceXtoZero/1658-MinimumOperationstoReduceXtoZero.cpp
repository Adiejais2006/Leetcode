// Last updated: 11/1/2026, 4:11:20 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int x) {
4        int n = nums.size();
5        int sum = 0 ;
6        for(auto it:nums) sum+=it;
7        int target  = sum-x;
8        if(target<0)return -1;
9        if(target==0)return n ;
10        sum= 0 ; 
11        int l = 0 ;
12        int r = 0 ;
13        int ans = -1 ;
14        while(r<n){
15            sum+=nums[r];
16            while(l<= r && sum>target){
17                sum-=nums[l++];
18            }
19            if(sum==target)
20            ans=max(ans,r-l+1);
21            r++;
22        }
23        return ans== -1? -1 : n -ans;
24    }
25};