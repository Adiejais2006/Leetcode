// Last updated: 11/3/2026, 12:13:49 PM
1class Solution {
2public:
3    int titleToNumber(string columnTitle) {
4        int ans = 0;
5        int n = columnTitle.size();
6        for (int i = 0; i < n; i++) {
7            ans += pow(26, (n - 1 - i)) * (columnTitle[i] - 'A' + 1);
8        }
9        return ans;
10    }
11};