// Last updated: 11/4/2026, 6:49:27 PM
1class Solution {
2public:
3    int maxLength(vector<string>& arr) {
4        vector<int> dp = {0};
5        int res = 0;
6        for (const string& s : arr) {
7            int a = 0, dup = 0;
8            for (char c : s) {
9                dup |= a & (1 << (c - 'a'));
10                a |= 1 << (c - 'a');
11            }
12            if (dup > 0)
13                continue;
14            for (int i = dp.size() - 1; i >= 0; i--) {
15                if ((dp[i] & a) > 0)
16                    continue;
17                dp.push_back(dp[i] | a);
18                res = max(res, __builtin_popcount(dp[i] | a));
19            }
20        }
21        return res;
22    }
23};