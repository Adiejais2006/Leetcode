// Last updated: 9/22/2026, 10:53:59 PM
1class Solution {
2public:
3    long long minimumCost(string source, string target, vector<char>& original,
4                          vector<char>& changed, vector<int>& cost) {
5        vector<vector<long long>> dist(26, vector<long long>(26, 1e18));
6        for (int i = 0; i < 26; i++) {
7            dist[i][i] = 0;
8        }
9        int n = original.size();
10        for (int i = 0; i < n; i++) {
11            int start = original[i] - 'a';
12            int end = changed[i] - 'a';
13            long long wt = cost[i];
14            dist[start][end] = min(dist[start][end], wt);
15        }
16        for (int k = 0; k < 26; k++) {
17            for (int i = 0; i < 26; i++) {
18                for (int j = 0; j < 26; j++) {
19                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
20                }
21            }
22        }
23        long long ans = 0;
24        for (int i = 0; i < target.size(); i++) {
25            if (dist[source[i] - 'a'][target[i] - 'a'] == 1e18)
26                return -1;
27            ans += dist[source[i] - 'a'][target[i] - 'a'];
28        }
29        return ans;
30    }
31};