// Last updated: 7/20/2026, 12:22:15 AM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_map<char, int> lastIndex;
5        int l = 0, ans = 0;
6        for (int r = 0; r < s.size(); r++) {
7            if (lastIndex.count(s[r]))
8                l = max(l, lastIndex[s[r]] + 1);
9
10            lastIndex[s[r]] = r;
11            ans = max(ans, r - l + 1);
12        }
13
14        return ans;
15    }
16};