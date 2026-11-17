// Last updated: 11/17/2026, 2:09:19 PM
1class Solution {
2    int ans = 0 ; 
3    int func( int node , int parent , vector<int>adj[], vector<bool>& hasApple){
4        bool found = hasApple[node];
5        for(auto it:adj[node]){
6            if(it==parent)continue;
7            bool child = func(it,node,adj,hasApple);
8            if(child){
9                ans+=2;
10                found = true;
11            }
12        }
13        return found;
14    }
15public:
16    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
17        vector<int>adj[n];
18        for(auto it:edges){
19            int u =it[0];
20            int v = it[1];
21            adj[u].push_back(v);
22            adj[v].push_back(u);
23        }
24         func(0,-1,adj,hasApple);
25         return ans ;
26    }
27};