// Last updated: 10/24/2026, 2:59:30 PM
1class Solution {
2public:
3    int integerBreak(int n) {
4        if (n == 2) return 1;
5        if (n == 3) return 2;
6        vector<int> dp(n + 1, 0);
7        dp[1] = 1; 
8        dp[2] = 1;
9        dp[3] = 2;
10        for (int i = 4; i <= n; i++) {
11            for (int j = 1; j <= i; j++) {
12                int x = j;
13                int y = i - j; 
14                int option1 = x * y;
15                int option2 = x * dp[y];
16                int option3 = dp[x] * y;
17                int option4 = dp[y] * dp[x];
18                dp[i] = max({dp[i], option1, option2, option3, option4});
19            }
20        }
21        return dp[n];
22    }
23};
24