// Last updated: 7/18/2026, 2:04:44 PM
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }

        vector<double> results;
        for (const auto& q : queries) {
            if (graph.find(q[0]) == graph.end() || graph.find(q[1]) == graph.end()) {
                results.push_back(-1.0);
            } else if (q[0] == q[1]) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                results.push_back(bfs(q[0], q[1], graph, visited));
            }
        }
        return results;
    }

private:
    double bfs(string start, string end, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        queue<pair<string, double>> q;
        q.push({start, 1.0});
        visited.insert(start);

        while (!q.empty()) {
            auto [curr, val] = q.front();
            q.pop();

            if (curr == end) return val;

            for (auto& neighbor : graph[curr]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    visited.insert(neighbor.first);
                    q.push({neighbor.first, val * neighbor.second});
                }
            }
        }
        return -1.0;
    }
};