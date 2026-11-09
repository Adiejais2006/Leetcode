// Last updated: 11/9/2026, 5:20:30 PM
1class Solution {
2public:
3    vector<string> findItinerary(vector<vector<string>>& tickets) {
4        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
5        for (const auto& ticket : tickets) {
6            graph[ticket[0]].push(ticket[1]);
7        }
8        vector<string> newItinerary;
9        stack<string> st;
10        st.push("JFK");
11        while (!st.empty()) {
12            string currentAirport = st.top();
13            if (graph.find(currentAirport) != graph.end() && !graph[currentAirport].empty()) {
14                st.push(graph[currentAirport].top());
15                graph[currentAirport].pop();
16            } else {
17                newItinerary.push_back(st.top());
18                st.pop();
19            }
20        }
21        reverse(newItinerary.begin(), newItinerary.end());
22        return newItinerary;        
23    }
24};