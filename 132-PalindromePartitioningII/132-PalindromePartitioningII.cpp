// Last updated: 10/22/2026, 6:56:47 PM
1class Solution {
2    bool isPalindrome(int i, int j, string& s) {
3        while (i < j) {
4            if (s[i++] != s[j--])
5                return false;
6        }
7        return true;
8    }
9
10public:
11    int minCut(string s) {
12        int n = s.size();
13        vector<int> dp(n+1, 0);
14        for (int i = n - 1; i >= 0; i--) {
15            int mincost = 1e9;
16
17            for (int j = i; j < s.size(); j++) {
18                if (isPalindrome(i, j, s)) {
19                    int cost = 1 + dp[j + 1];
20                    mincost = min(mincost, cost);
21                }
22            }
23
24            dp[i] = mincost;
25        }
26        return dp[0] - 1;
27    }
28};
29