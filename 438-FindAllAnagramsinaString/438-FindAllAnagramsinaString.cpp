// Last updated: 11/4/2026, 9:05:13 PM
1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        int n = s.size();
5        int m = p.size();
6        if (m > n)
7            return {};
8        vector<int> fromMatch(26, 0);
9        for (auto it : p) {
10            fromMatch[it - 'a']++;
11        }
12        int l = 0;
13        int r = 0;
14        vector<int> ans;
15        vector<int> toMatch(26, 0);
16        for (r; r < m; r++) {
17            char ch = s[r] - 'a';
18            toMatch[ch]++;
19        }
20        if (toMatch == fromMatch)
21            ans.push_back(l);
22        while (r < n) {
23            toMatch[s[r] - 'a']++;
24            toMatch[s[l] - 'a']--;
25            l++;
26            r++;
27            if (toMatch == fromMatch)
28                ans.push_back(l);
29        }
30        return ans;
31    }
32};