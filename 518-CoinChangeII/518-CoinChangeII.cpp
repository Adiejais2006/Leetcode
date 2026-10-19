// Last updated: 10/19/2026, 3:40:51 PM
1class Solution {
2public:
3    int change(int amount, vector<int>& coins) {
4        int n = coins.size();
5        vector<unsigned long long> prev(amount + 1, 0);
6        vector<unsigned long long> curr(amount + 1, 0);
7        for (int i = 0; i <= amount; i++) {
8            prev[i] = (i % coins[0] == 0) ? 1 : 0;
9        }
10        for (int i = 1; i < n; i++) {
11            for (int j = 0; j <= amount; j++) {
12                unsigned long long nottake = prev[j];
13                unsigned long long take = 0;
14                if (j >= coins[i]) {
15                    take = curr[j - coins[i]];
16                }
17                curr[j] = take + nottake;
18            }
19            prev = curr;
20        }
21        return (int)prev[amount];
22    }
23};