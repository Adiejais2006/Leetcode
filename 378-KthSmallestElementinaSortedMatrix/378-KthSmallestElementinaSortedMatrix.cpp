// Last updated: 7/22/2026, 12:02:09 AM
1class Solution {
2public:
3    int kthSmallest(vector<vector<int>>& matrix, int k) {
4        int n = matrix.size();
5        priority_queue<pair<int, pair<int, int>>,
6                       vector<pair<int, pair<int, int>>>,
7                       greater<pair<int, pair<int, int>>>>
8            pq;
9
10        pq.push({matrix[0][0], {0, 0}});
11
12        vector<vector<int>> vis(n, vector<int>(n, 0));
13        int dx[] = {1, 0};
14        int dy[] = {0, 1};
15
16        while (k>1) {
17            auto it = pq.top();
18            pq.pop();
19            int valu = it.first;
20            int x = it.second.first;
21            int y = it.second.second;
22            for (int i = 0; i < 2; i++) {
23                int nx = x + dx[i];
24                int ny = y + dy[i];
25                if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[nx][ny]) {
26                    vis[nx][ny] = 1; 
27                    pq.push({matrix[nx][ny], {nx, ny}});
28                }
29            }
30            k--;
31        }
32
33       
34        return pq.top().first;
35    }
36};