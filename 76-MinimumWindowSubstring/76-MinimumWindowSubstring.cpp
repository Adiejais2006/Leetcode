// Last updated: 7/18/2026, 11:23:06 PM
1class Solution {
2public:
3    string minWindow(string s, string t) {
4        int n = s.size();
5        int m = t.size();
6        string ans = "";
7        int l = 0;
8        int r = 0;
9        unordered_map<char, int> tmap, smap;
10        for (char c : t)
11            tmap[c]++;
12        int matched = 0;
13        int required = tmap.size();
14        int minlen = INT_MAX;
15        int start = -1;
16        int end = -1;
17        while (r < n) {
18            char c = s[r];
19            smap[c]++;
20            if (tmap.count(c) && smap[c] == tmap[c])
21                matched++;
22            while (matched == required) {
23                if (r - l + 1 < minlen) {
24                    start = l;
25                    end = r - l + 1;
26                    minlen = r - l + 1;
27                }
28                smap[s[l]]--;
29                if (tmap.count(s[l]) && smap[s[l]] < tmap[s[l]])
30                    matched--;
31
32                l++;
33            }
34            r++;
35        }
36        if(start==-1) return "";
37        return s.substr(start, end);
38    }
39};