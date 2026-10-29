// Last updated: 10/29/2026, 11:57:09 PM
1class Solution {
2    int func(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
3        if (i == s1.size()) {
4            int sum = 0;
5            while (j < s2.size()) {
6                sum += s2[j++];
7            }
8                return sum;
9        }
10        if (j == s2.size()) {
11            int sum = 0;
12            while (i < s1.size()) {
13                sum += s1[i++];
14            }
15                return sum;
16        }
17        if(dp[i][j]!=-1)return dp[i][j];
18        if (s1[i] == s2[j]) {
19            return dp[i][j] =  func(i + 1, j + 1, s1, s2, dp);
20        } else {
21            return dp[i][j] =  min(s1[i] + func(i + 1, j, s1, s2, dp),
22                       s2[j] + func(i, j + 1, s1, s2, dp));
23        }
24    }
25
26public:
27    int minimumDeleteSum(string s1, string s2) {
28        int n = s1.size();
29        int m = s2.size();
30        vector<vector<int>> dp(n, vector<int>(m, -1));
31        return func(0, 0, s1, s2, dp);
32    }
33};