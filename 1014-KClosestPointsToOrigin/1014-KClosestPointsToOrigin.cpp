// Last updated: 7/18/2026, 2:02:52 PM
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int x = points[i][0];
            int y = points[i][1];
            int ans = x * x + y * y;
            pq.push({ans, i});
        }
        vector<vector<int>> ans;

        while (!pq.empty() && k > 0) {
            k--;
            auto it = pq.top();
            pq.pop();
            int ind = it.second;
            ans.push_back(points[ind]);
        }

        return ans;
    }
};