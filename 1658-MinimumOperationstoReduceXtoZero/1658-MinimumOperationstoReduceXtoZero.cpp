// Last updated: 11/13/2026, 1:13:53 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums, int x) {
4        int n = nums.size();
5        int sum = 0;
6        for (auto it : nums)
7            sum += it;
8        int target = sum - x;
9        if (target < 0)
10            return -1;
11        if (target == 0)
12            return n;
13        sum = 0;
14        int l = 0 ; 
15        int r  = 0 ;
16        int ans =-1;
17        while(r<n){
18            sum+=nums[r];
19            while(l<=r && sum>target){
20                sum-=nums[l++];
21            }
22            if(sum==target)
23            ans=max(ans,r-l+1);
24            r++;
25        }
26        return ans==-1? -1:n-ans;
27    }
28};