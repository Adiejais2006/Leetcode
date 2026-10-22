// Last updated: 10/22/2026, 3:02:38 PM
1class Solution {
2    int lcs(string &s1,  string &s2) {
3        int n = s1.size();
4        int m = s2.size();
5        vector<int> prev(m + 1, 0);
6        vector<int> curr(m + 1, 0);
7        for (int i = n - 1; i >= 0; i--) {
8            for (int j = m - 1; j >= 0; j--) {
9                if (s1[i] == s2[j]) {
10                    curr[j] = 1 + prev[j + 1];
11                } else
12                    curr[j] = max(prev[j], curr[j + 1]);
13            }
14            prev = curr;
15        }
16        return prev[0];
17    }
18
19public:
20    int minInsertions(string s) {
21        int n = s.size();
22        string orig = s;
23        reverse(orig.begin(), orig.end());
24        int lcss = lcs(s, orig);
25        return n - lcss;
26    }
27};