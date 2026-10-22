// Last updated: 10/22/2026, 6:55:51 PM
1
2class Solution {
3    bool isPalindrome(int i, int j, string& s) {
4        while (i < j) {
5            if (s[i++] != s[j--])
6                return false;
7        }
8        return true;
9    }
10
11    int func(int i, string& s, vector<int>& dp) {
12        if (i >= s.size())
13            return 0;
14
15        if (dp[i] != -1)
16            return dp[i];
17
18        int mincost = 1e9;
19
20        for (int j = i; j < s.size(); j++) {
21            if (isPalindrome(i, j, s)) {
22                int cost = 1 + func(j + 1, s, dp);
23                mincost = min(mincost, cost);
24            }
25        }
26
27        return dp[i] = mincost;
28    }
29
30public:
31    int minCut(string s) {
32        int n = s.size();
33        vector<int> dp(n, -1);
34        return func(0, s, dp) - 1;
35    }
36};
37
38