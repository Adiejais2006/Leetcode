// Last updated: 10/23/2026, 12:25:37 PM
1class Solution {
2public:
3    int lengthOfLongestSubstring(string s) {
4        unordered_map<int, int> mpp;
5        int n = s.size();
6        int l = 0;
7        int ans = 0;
8        for (int r = 0; r < n; r++) {
9            if (mpp.count(s[r])) {
10                l = max(l, mpp[s[r]]+1);
11            }
12            mpp[s[r]] = r;
13            ans = max(ans, r - l + 1);
14        }
15        return ans;
16    }
17};