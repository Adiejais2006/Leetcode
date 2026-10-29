// Last updated: 10/29/2026, 3:28:30 PM
1class Solution {
2    int func(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
3        if (amount == 0)
4            return 1;
5        if (i == coins.size() - 1) {
6            if (amount % coins[i] == 0 || amount == 0)
7                return 1;
8            return 0;
9        }
10        if (dp[i][amount] != -1)
11            return dp[i][amount];
12        int notpick = func(i + 1, amount, coins, dp);
13        int pick = 0;
14        if (amount >= coins[i])
15            pick = func(i, amount - coins[i], coins, dp);
16        return dp[i][amount] = pick + notpick;
17    }
18
19    int tab(int amount, vector<int>& coins) {
20        int n = coins.size();
21        vector<vector<unsigned long long>> dp(
22            n + 1, vector<unsigned long long>(amount + 1, 0));
23        // base cases
24        // amount==0
25        for (int i = 0; i < n; i++)
26            dp[i][0] = 1;
27        // if i==n-1 then if divisbile by nums[n-1] then 1 else 0
28        for (int i = 0; i <= amount; i++) {
29            if (i % coins[n - 1] == 0)
30                dp[n - 1][i] = 1;
31            else
32                dp[n - 1][i] = 0;
33        }
34        for (int i = n - 2; i >= 0; i--) {
35            for (int amt = 0; amt <= amount; amt++) {
36                unsigned long long notpick = dp[i + 1][amt];
37                unsigned long long pick = 0;
38                if (amt >= coins[i])
39                    pick = dp[i][amt - coins[i]];
40                dp[i][amt] = pick + notpick;
41            }
42        }
43        return dp[0][amount];
44    }
45    int spaceop(int amount, vector<int>& coins) {
46        int n = coins.size();
47        vector<unsigned long long> prev(amount + 1, 0);
48        vector<unsigned long long> curr(amount + 1, 0);
49        // base cases
50        // amount==0
51            prev[0] = 1;
52        // if i==n-1 then if divisbile by nums[n-1] then 1 else 0
53        for (int i = 0; i <= amount; i++) {
54            if (i % coins[n - 1] == 0)
55                prev[i] = 1;
56            else
57                prev[i] = 0;
58        }
59        for (int i = n - 2; i >= 0; i--) {
60            for (int amt = 0; amt <= amount; amt++) {
61                unsigned long long notpick = prev[amt];
62                unsigned long long pick = 0;
63                if (amt >= coins[i])
64                    pick = curr[amt - coins[i]];
65                curr[amt] = pick + notpick;
66            }
67            prev = curr;
68        }
69        return prev[amount];
70    }
71
72public:
73    int change(int amount, vector<int>& coins) {
74        int n = coins.size();
75        // vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
76        // return func(0, amount, coins, dp);
77        // return tab(amount, coins);
78        return spaceop(amount, coins);
79    }
80};