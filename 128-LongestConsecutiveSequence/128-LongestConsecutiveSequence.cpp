// Last updated: 10/18/2026, 6:32:40 PM
1class Solution {
2public:
3    int longestConsecutive(vector<int>& nums) {
4       unordered_set<int> mpp(nums.begin(), nums.end());
5        int ans = 0;
6        for (auto it : mpp) {
7            int el = it;
8            int cnt = 0;
9            if (mpp.find(it + 1) == mpp.end()) {
10                while (mpp.find(el) != mpp.end()) {
11                    cnt++;
12                    el--;
13                }
14            }
15            ans = max(ans, cnt);
16        }
17
18        return ans;
19    }
20};