// Last updated: 7/18/2026, 2:00:46 PM
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n);

        for (auto &road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }

        vector<pair<int, int>> order;

        for (int i = 0; i < n; i++) {
            order.push_back({degree[i], i});
        }

        sort(order.begin(), order.end());

        vector<long long> value(n);

        for (int i = 0; i < n; i++) {
            value[order[i].second] = i + 1;
        }

        long long ans = 0;

        for (auto &road : roads) {
            ans += value[road[0]] + value[road[1]];
        }

        return ans;
    }
};