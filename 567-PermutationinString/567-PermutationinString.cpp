// Last updated: 10/27/2026, 1:47:00 PM
1class Solution {
2public:
3    bool checkInclusion(string s1, string s2) {
4        int n = s1.size();
5        int m = s2.size();
6        if (n > m)
7            return false;
8        vector<int> frommatch(26, 0);
9        for (auto it : s1) {
10            frommatch[it - 'a']++;
11        }
12        vector<int> inmatch(26, 0);
13        int l = 0;
14        int r = 0;
15        while (r < n) {
16            inmatch[s2[r]-'a']++;
17            r++;
18        }
19        if (inmatch == frommatch)
20            return true;
21        while (r < m) {
22            inmatch[s2[r]-'a']++;
23            inmatch[s2[l]-'a']--;
24            if (inmatch == frommatch)
25                return true;
26            l++;
27            r++;
28        }
29        return false;
30    }
31};