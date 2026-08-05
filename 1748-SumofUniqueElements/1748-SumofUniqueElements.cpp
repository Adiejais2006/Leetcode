// Last updated: 8/5/2026, 4:55:32 PM
1class Solution {
2public:
3    int sumOfUnique(vector<int>& nums) {
4        unordered_map<int, int> mpp;
5        for (int num : nums)
6            mpp[num]++;
7        int ans = 0;
8        for (auto it : mpp) {
9            if (it.second == 1)
10                ans += it.first;
11        }
12        return ans;
13    }
14};