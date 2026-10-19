// Last updated: 10/19/2026, 3:14:31 PM
1class Solution {
2
3public:
4    int coinChange(vector<int>& coins, int a) {
5        int n = coins.size();
6        vector<int> prev(a + 1, 0);
7        vector<int> curr(a + 1, 0);
8        prev[0] = 0;
9        for (int i = 0; i <= a; i++) {
10            if (i % coins[0] == 0)
11                prev[i] = i / coins[0];
12            else
13                prev[i] = 1e9;
14        }
15        for (int i = 1; i < n; i++) {
16            for (int amount = 0; amount <= a; amount++) {
17                int nottake = prev[amount];
18                int take = 1e9;
19                if (amount >= coins[i]) {
20                    take = 1 + curr[amount - coins[i]];
21                }
22                curr[amount] = min(take, nottake);
23            }
24            prev = curr;
25        }
26        int ans = prev[a];
27        return (ans == 1e9) ? -1 : ans;
28    }
29};