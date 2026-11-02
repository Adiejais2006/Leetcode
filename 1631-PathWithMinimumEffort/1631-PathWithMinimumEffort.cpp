// Last updated: 11/2/2026, 4:47:10 PM
1class Solution {
2public:
3    int minimumEffortPath(vector<vector<int>>& heights) {
4        int n = heights.size();
5        int m = heights[0].size();
6        priority_queue<pair<int, pair<int, int>>,
7                       vector<pair<int, pair<int, int>>>,
8                       greater<pair<int, pair<int, int>>>>
9            q; // dist x y
10        q.push({0, {0, 0}});
11        vector<vector<int>> dist(n, vector<int>(m, 1e9));
12        dist[0][0] = 0;
13        int dx[] = {0, 0, -1, 1};
14        int dy[] = {-1, 1, 0, 0};
15        while (!q.empty()) {
16            auto [diff, cords] = q.top();
17            q.pop();
18            auto x = cords.first;
19            auto y = cords.second;
20            for(int i = 0 ; i< 4 ; i++){
21                int nx = x + dx[i];
22                int ny = y + dy[i];
23                if(nx>=0 && nx < n && ny>=0 && ny<m){
24                    int adjCost = heights[nx][ny];
25                    int cost = max(diff ,abs(heights[x][y] - heights[nx][ny]));
26                    if(dist[nx][ny]> cost){
27                        dist[nx][ny] = cost;
28                        q.push({cost ,{nx,ny}});
29                    }
30                }
31            }
32        }
33        return dist[n - 1][m - 1];
34    }
35};