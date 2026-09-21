// Last updated: 9/21/2026, 7:21:16 PM
1    class Solution {
2    public:
3        double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
4            vector<pair<int,double>> adj[n];
5            int i = 0 ;
6            for(auto it : edges){
7                int u = it[0];
8                int v =  it[1];
9                double wt = succProb[i++];
10                adj[u].push_back({v,wt});
11                adj[v].push_back({u,wt});
12            }
13            vector<double> dist(n,0);
14            dist[start_node] = 1  ; 
15            priority_queue< pair<double,int>>q;
16            q.push({1,start_node});
17            while(!q.empty()){
18                auto [currDist , node] = q.top();
19                q.pop();
20                for(auto it:adj[node]){
21                    int adjNode = it.first;
22                    double adjDist = it.second;
23                    double totalDist = currDist * adjDist;
24                    if(totalDist > dist[adjNode]){
25                        dist[adjNode] = totalDist;
26                        q.push({totalDist , adjNode});
27                    }
28                }
29            }
30
31            return  dist[end_node];
32        }
33    };