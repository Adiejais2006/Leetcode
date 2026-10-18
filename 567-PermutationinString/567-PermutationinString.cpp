// Last updated: 10/18/2026, 7:30:19 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6        if (n > m)
7            return false;
8        vector<int> freq1(26, 0);
9        vector<int> freq2(26, 0);
10        for (auto it : s1) {
11            freq1[it - 'a']++;
12        }
13        int l = 0;
14        int r = 0;
15        for (r; r < n; r++) {
16            freq2[s2[r]-'a']++;
17        }
18        if (freq1 == freq2)
19            return true;
20        while (r < m) {
21            freq2[s2[r]-'a']++;
22            freq2[s2[l]-'a']--;
23            r++;
24            l++;
25            if (freq1 == freq2)
26                return true;
27        }
28        return false;
29    }
30};