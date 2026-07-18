// Last updated: 7/18/2026, 2:04:54 PM
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int n = coins.size();
        vector<int> before(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                before[i] = i / coins[0];
            else
                before[i] = 1e9;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int a = 0; a <= amount; a++) {
                int pick = 1e9;
                if (coins[ind] <= a) pick = 1 + curr[a - coins[ind]];
                int notpick = before[a];
                curr[a] = min(pick, notpick);
            }
            before=curr;
        }
        int ans = before[amount];
        return (ans >= 1e9) ? -1 : ans;
    }
};