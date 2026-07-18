// Last updated: 7/19/2026, 12:04:24 AM
1class Solution {
2public:
3    vector<int> findAnagrams(string s, string p) {
4        int n = s.size();
5        int m = p.size();
6        if (n < m)
7            return {};
8        int l = 0;
9        int r = 0;
10        vector<int> need(26, 0);
11        for (int i = 0; i < m; i++) {
12            need[p[i] - 'a']++;
13        }
14        vector<int> want(26, 0);
15        vector<int> ans;
16        for (r; r < m; r++) {
17            want[s[r] - 'a']++;
18        }
19        if (want == need)
20            ans.push_back(0);
21        while (r < n) {
22            want[s[r] - 'a']++;
23            want[s[l] - 'a']--;
24            r++;
25            l++;
26            if (want == need)
27                ans.push_back(l);
28        }
29        return ans;
30    }
31};