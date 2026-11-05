// Last updated: 11/5/2026, 4:06:47 PM
1class Solution {
2public:
3    int subarraysDivByK(vector<int>& nums, int k) {
4        int n = nums.size();
5        int ans = 0;
6        unordered_map<int, int> mpp;
7        mpp[0] = 1;
8        for (int i = 0; i < n; i++) {
9            sum += nums[i];
10            int r = (sum % k + k) % k;
11            if (mpp.find(r) != mpp.end()) {
12                ans += mpp[r];
13            }
14            mpp[r]++;
15        }
16        return ans;
17    }
18};