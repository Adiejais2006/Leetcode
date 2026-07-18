// Last updated: 7/18/2026, 2:01:27 PM
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for (int i = 1; i < m; i++) {
            int d = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i - 1][1] + d);
        }

        for (int i = m - 2; i >= 0; i--) {
            int d = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] =
                min(restrictions[i][1], restrictions[i + 1][1] + d);
        }

        long long ans = 0;

        for (int i = 1; i < m; i++) {
            int x1 = restrictions[i - 1][0];
            int h1 = restrictions[i - 1][1];

            int x2 = restrictions[i][0];
            int h2 = restrictions[i][1];

            int d = x2 - x1;

            long long peak = (1LL * h1 + h2 + d) / 2;

            ans = max(ans, peak);
        }

        return (int)ans;
    }
};