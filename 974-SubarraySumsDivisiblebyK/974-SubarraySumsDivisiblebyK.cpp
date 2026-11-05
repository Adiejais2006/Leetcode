// Last updated: 11/5/2026, 4:06:54 PM
1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        int n = nums.size();
5        int ans = 0;
6        int sum = 0 ; 
7        unordered_map<int, int> mpp;
8        mpp[0] = 1;
9        for (int i = 0; i < n; i++) {
10            sum += nums[i];
11            int r = (sum % k + k) % k;
12            if (mpp.find(r) != mpp.end()) {
13                ans += mpp[r];
14            }
15            mpp[r]++;
16        }
17        return ans;
18    }
19};