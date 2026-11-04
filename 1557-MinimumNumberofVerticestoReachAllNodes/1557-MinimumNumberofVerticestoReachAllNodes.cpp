// Last updated: 11/4/2026, 9:11:31 PM
1class Solution {
2public:
3    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
4        vector<int> ans;
5        vector<int> indegree(n, 0);
6        for (auto it : edges) {
7            int v = it[1];
8            indegree[v]++;
9        }
10        for (int i = 0; i < n; i++) {
11            if (indegree[i] == 0)
12                ans.push_back(i);
13        }
14        return ans;
15    }
16};