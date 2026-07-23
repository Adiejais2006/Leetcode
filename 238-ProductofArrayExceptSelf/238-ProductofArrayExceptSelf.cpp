// Last updated: 7/24/2026, 12:25:42 AM
1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        int n=nums.size();
5        vector<int>v(n,1);
6        for(int i=1;i<n;i++) {
7            v[i]=nums[i-1]*v[i-1];
8        }
9        vector<int>u(n,1);
10        for(int i=n-2;i>=0;i--) {
11            u[i]=nums[i+1]*u[i+1];
12        }
13        for(int i=n-1;i>=0;i--) {
14            u[i]=v[i]*u[i];
15        }
16        return u;
17
18    }
19};