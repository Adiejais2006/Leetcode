// Last updated: 11/10/2026, 7:28:45 PM
1class Solution {
2public:
3    int climbStairs(int n, vector<int>& costs) {
4        int a = 0, b = 0, c = 0;
5
6        for (int i = n - 2; i >= -1; i--) {
7            int curr = INT_MAX;
8
9            for (int j = i + 1; j <= i + 3 && j < n; j++) {
10                int next = (j == i + 1) ? a :
11                           (j == i + 2) ? b : c;
12
13                curr = min(curr, costs[j] +
14                            (j - i) * (j - i) + next);
15            }
16
17            c = b;
18            b = a;
19            a = curr;
20        }
21
22        return a;
23    }
24};