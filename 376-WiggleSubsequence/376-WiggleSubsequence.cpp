// Last updated: 10/31/2026, 10:49:05 PM
1class Solution {
2public:
3    int wiggleMaxLength(vector<int>& nums) {
4        int n = nums.size();
5        if (n < 2) return n;
6        int prevDiff = 0;
7        int ans = 1;
8        for (int i = 1; i < n; i++) {
9            int diff = nums[i] - nums[i - 1];
10            if ((diff > 0 && prevDiff <= 0) ||
11                (diff < 0 && prevDiff >= 0)) {
12                ans++;
13                prevDiff = diff;
14            }
15        }
16        return ans;
17    }
18};