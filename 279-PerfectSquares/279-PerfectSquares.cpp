// Last updated: 10/19/2026, 4:12:12 PM
1class Solution {
2public:
3    int numSquares(int m) {
4        vector<int> coins;
5        for (int i = 1; i <= m; i++) {
6            int number = i * i;
7            if (number <= m) {
8                coins.push_back(number);
9            } else
10                break;
11        }
12        int n = coins.size();
13        int a = m;
14        vector<int> prev(a + 1, 0);
15        vector<int> curr(a + 1, 0);
16        prev[0] = 0;
17        for (int i = 0; i <= a; i++) {
18            if (i % coins[0] == 0)
19                prev[i] = i / coins[0];
20            else
21                prev[i] = 1e9;
22        }
23        for (int i = 1; i < n; i++) {
24            for (int amount = 0; amount <= a; amount++) {
25                int nottake = prev[amount];
26                int take = 1e9;
27                if (amount >= coins[i]) {
28                    take = 1 + curr[amount - coins[i]];
29                }
30                curr[amount] = min(take, nottake);
31            }
32            prev = curr;
33        }
34        int ans = prev[a];
35        return (ans == 1e9) ? -1 : ans;
36    }
37};