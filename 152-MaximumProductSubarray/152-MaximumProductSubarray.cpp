// Last updated: 11/6/2026, 6:34:20 PM
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        int n = nums.size();
5        int ans = INT_MIN;
6        int pre =1;
7        int suff =1;
8        for(int i  =0 ; i<nums.size() ; i++){
9            if(pre==0)pre=1;
10            if(suff==0)suff=1;
11            pre*= nums[i];
12            suff*=nums[n-1-i];
13            ans=max(ans,max(pre,suff));
14        }
15        return ans ;
16    }
17};