// Last updated: 11/13/2026, 2:28:41 PM
1class Solution {
2public:
3    int numOfMinutes(int n, int headID, vector<int>& manager,
4                     vector<int>& informTime) {
5        vector<int> adj[n];
6        for (int i = 0; i < n; i++) {
7            if (manager[i] != -1) {
8                adj[manager[i]].push_back(i);
9            }
10        }
11        queue<pair<int,int>> q; // id aur time 
12        q.push({headID,0});
13        vector<int>vis(n,0);
14        vis[headID]=1;
15        int ans = -1 ; 
16        while(!q.empty()){
17            auto [node,time] = q.front();
18            q.pop();        
19            ans=max(ans,time);
20            for(auto it:adj[node]){
21                if(!vis[it]){
22                    vis[it]=1;
23                    q.push({it,time+informTime[node]});
24                }
25            }
26        }
27        return ans ;
28    }
29};