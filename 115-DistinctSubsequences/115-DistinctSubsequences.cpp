// Last updated: 10/20/2026, 6:45:55 PM
1class Solution {
2public:
3    int numDistinct(string s, string t) {
4        int n = s.size();
5        int m = t.size();
6        vector<unsigned long long> prev(m + 1, 0);
7        vector<unsigned long long> curr(m + 1, 0);
8        prev[0] = 1;curr[0] = 1;
9
10        for (int i = 1; i <= n; i++) {
11            for (int j = 1; j <= m; j++) {
12                unsigned long long pick = 0;
13                if (s[i - 1] == t[j - 1])
14                    pick =prev[j - 1];
15                unsigned long long notpick = prev[j];
16                curr[j] = pick + notpick;
17            }
18            prev = curr;
19        }
20        return prev[m];
21    }
22};