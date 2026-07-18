// Last updated: 7/18/2026, 2:00:36 PM
class Solution {
public:
    long long dp[105][105];

    long long solve(int i, int j, vector<int>& robot,
                    vector<vector<int>>& factory) {
        if (i == robot.size()) return 0;
        if (j == factory.size()) return 1e18;

        if (dp[i][j] != -1) return dp[i][j];

        long long ans = solve(i, j + 1, robot, factory);

        long long cost = 0;

        for (int k = 0; k < factory[j][1] && i + k < robot.size(); k++) {
            cost += abs(robot[i + k] - factory[j][0]);
            ans = min(ans,
                      cost + solve(i + k + 1, j + 1, robot, factory));
        }

        return dp[i][j] = ans;
    }

    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        memset(dp, -1, sizeof(dp));

        return solve(0, 0, robot, factory);
    }
};