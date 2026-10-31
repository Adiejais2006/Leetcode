// Last updated: 10/31/2026, 10:41:07 PM
1class Solution {
2public:
3    int strStr(string haystack, string needle) {
4        int m = haystack.length(), n = needle.length();
5        if (n == 0) return 0;
6        
7        vector<int> lps(n, 0);
8        for (int i = 1; i < n; ++i) {
9            int j = lps[i - 1];
10            while (j > 0 && needle[i] != needle[j]) {
11                j = lps[j - 1];
12            }
13            if (needle[i] == needle[j]) {
14                j++;
15            }
16            lps[i] = j;
17        }
18        
19        int i = 0, j = 0;
20        while (i < m) {
21            if (haystack[i] == needle[j]) {
22                i++;
23                j++;
24            }
25            if (j == n) {
26                return i - n;
27            } else if (i < m && haystack[i] != needle[j]) {
28                if (j != 0) {
29                    j = lps[j - 1];
30                } else {
31                    i++;
32                }
33            }
34        }
35        return -1;
36    }
37};