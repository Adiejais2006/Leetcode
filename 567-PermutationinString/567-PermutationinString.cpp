// Last updated: 7/19/2026, 11:13:35 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int l = 0;
5        int r = 0;
6        int m = s1.size();
7        int n = s2.size();
8        if(m>n) return false;
9        vector<int> to(26);
10        vector<int> in(26);
11        for (auto it : s1) {
12            to[it - 'a']++;
13        }
14        for (r; r < m; r++) {
15            in[s2[r] - 'a']++;
16        }
17        if (to == in)
18            return true;
19
20        while (r < n) {
21            in[s2[r] - 'a']++;
22            in[s2[l] - 'a']--;
23            r++;
24            l++;
25            if (in == to)
26                return true;
27        }
28        return false;
29    }
30};