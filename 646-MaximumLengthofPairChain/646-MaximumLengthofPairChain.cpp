// Last updated: 10/23/2026, 5:03:15 PM
1class Solution {
2
3public:
4    int findLongestChain(vector<vector<int>>& pairs) {
5        int n = pairs.size();
6        sort(pairs.begin(), pairs.end());
7        vector<int> prevv(n + 1,0);
8        vector<int> curr(n + 1,0);
9        for (int i = n - 1; i >= 0; i--) {
10            for (int prev = n - 1; prev >= -1; prev--) {
11                int nottake = prevv[prev+1];
12                int take = 0;
13                if (prev == -1 || pairs[prev][1] < pairs[i][0]) {
14                    take = 1 + prevv[i+1];
15                }
16              curr[prev + 1] = max(take, nottake);
17            }
18            prevv = curr;
19        }
20        return prevv[-1 + 1];
21    }
22};