// Last updated: 7/18/2026, 2:04:42 PM
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);

        for (int stone : stones) {
            for (int k : dp[stone]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump > 0) {
                        int nextStone = stone + jump;
                        if (binary_search(stones.begin(), stones.end(), nextStone))
                            dp[nextStone].insert(jump);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};