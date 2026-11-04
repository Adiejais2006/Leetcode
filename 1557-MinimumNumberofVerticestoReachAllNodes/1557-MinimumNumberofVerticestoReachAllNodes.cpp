// Last updated: 11/4/2026, 9:10:40 PM
1class Solution {
2public:
3    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
4        vector<int>adj[n];
5        vector<int>ans;
6        vector<int>indegree(n,0);
7        for(auto it:edges){
8            int u =it[0];
9            int v = it[1];
10            indegree[v]++;
11            adj[u].push_back(v);
12        }   
13        for(int i = 0 ; i<n ; i++){
14            if(indegree[i]==0)ans.push_back(i);
15        }
16        return ans ;
17
18    }
19};