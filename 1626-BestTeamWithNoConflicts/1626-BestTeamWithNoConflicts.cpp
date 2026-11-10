// Last updated: 11/10/2026, 10:36:07 PM
1class Solution {
2public:
3    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
4        vector<pair<int, int>> nums;
5        int n = scores.size();
6        for (int i = 0; i < n; i++) {
7            nums.push_back({ages[i], scores[i]});
8        }
9        sort(nums.begin(), nums.end());
10        vector<int> dp(n);
11        int ans = 0;
12        for (int i = 0; i < n; i++) {
13            int score = nums[i].second;
14            dp[i] = score;
15
16            for (int j = 0; j < i; j++) {
17                if (nums[j].second<=nums[i].second) {
18                    dp[i] = max(dp[i], dp[j]+score);
19                }
20            }
21            ans = max(ans, dp[i]);
22        }
23        return ans;
24    }
25};