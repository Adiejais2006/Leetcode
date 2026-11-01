// Last updated: 11/1/2026, 2:12:33 PM
1class Solution {
2    int func(vector<int>& nums, int k){
3          int n = nums.size();
4        int l = 0;
5        int r = 0;
6        int ans = 0;
7        unordered_map<int, int> mpp;
8        while (r < n) {
9            mpp[nums[r]]++;
10            while (mpp.size() > k) {
11                mpp[nums[l]]--;
12                if (mpp[nums[l]] == 0)
13                    mpp.erase(nums[l]);
14                l++;
15            }
16            ans+=r-l+1;
17            r++;
18        }
19
20        return ans;
21    }
22public:
23    int subarraysWithKDistinct(vector<int>& nums, int k) {
24      return func(nums,k)-func(nums,k-1);
25    }
26};