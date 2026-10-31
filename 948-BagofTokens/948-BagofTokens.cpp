// Last updated: 10/31/2026, 9:53:47 PM
1class Solution {
2public:
3    int bagOfTokensScore(vector<int>& tokens, int power) {
4        sort(tokens.begin(), tokens.end());
5        int n = tokens.size();
6        int l = 0;
7        int r = n - 1;
8        int score = 0;
9        int ans = 0;
10        while (l <= r) {
11            if (power >= tokens[l]) {
12                score++;
13                power -= tokens[l++];
14                ans = max(ans, score);
15            } else if (score > 0 && l < r) {
16                power += tokens[r--];
17                score--;
18            } else
19                break;
20        }
21        return ans;
22    }
23};