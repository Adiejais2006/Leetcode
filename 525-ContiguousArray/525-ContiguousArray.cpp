// Last updated: 11/6/2026, 5:28:21 PM
1class Solution {
2public:
3    int findMaxLength(vector<int>& nums) {
4        int n = nums.size();
5        for(int i = 0 ; i<n ; i++){
6            if(nums[i]==1) nums[i]=-1;
7            if(nums[i]==0)nums[i]=1;
8        }
9        int l = 0;
10        int r = 0;
11        unordered_map<int, int> mpp;
12        mpp[0] = -1;
13        int sum = 0;
14        int ans = 0;
15        while (r < n) {
16            sum += nums[r];
17            int rem = sum;
18            if (mpp.find(rem) != mpp.end()) {
19                ans = max(ans, r - mpp[rem]);
20            }
21            if(mpp.find(rem)==mpp.end())
22            mpp[rem] = r;
23            r++;
24        }
25        return ans;
26    }
27};