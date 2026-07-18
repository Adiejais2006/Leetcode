// Last updated: 7/18/2026, 11:03:40 PM
1class Solution {
2public:
3    string minWindow(string s, string t) {
4        unordered_map<char, int> need, have;
5
6        for (char c : t) need[c]++;
7
8        int required = need.size();
9        int formed = 0;
10
11        int l = 0;
12        int minLen = INT_MAX;
13        int start = 0;
14
15        for (int r = 0; r < s.size(); r++) {
16            char c = s[r];
17            have[c]++;
18
19            if (need.count(c) && have[c] == need[c])
20                formed++;
21
22            while (formed == required) {
23                if (r - l + 1 < minLen) {
24                    minLen = r - l + 1;
25                    start = l;
26                }
27
28                char leftChar = s[l];
29                have[leftChar]--;
30
31                if (need.count(leftChar) &&
32                    have[leftChar] < need[leftChar])
33                    formed--;
34
35                l++;
36            }
37        }
38
39        return minLen == INT_MAX
40                   ? ""
41                   : s.substr(start, minLen);
42    }
43};