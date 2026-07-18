// Last updated: 7/18/2026, 2:02:48 PM
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1);

        for (int i = n - 1; i >= 0; i--) {
            int j = i;

            while (j < n && days[j] < days[i] + 1)
                j++;
            int one = costs[0] + dp[j];

            j = i;
            while (j < n && days[j] < days[i] + 7)
                j++;
            int seven = costs[1] + dp[j];

            j = i;
            while (j < n && days[j] < days[i] + 30)
                j++;
            int thirty = costs[2] + dp[j];

            dp[i] = min({one, seven, thirty});
        }

        return dp[0];
    }
};