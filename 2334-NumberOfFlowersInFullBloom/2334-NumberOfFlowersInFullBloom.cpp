// Last updated: 7/18/2026, 2:00:48 PM
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start, end;

        for (auto &f : flowers) {
            start.push_back(f[0]);
            end.push_back(f[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> ans;

        for (int t : people) {
            int bloomed = upper_bound(start.begin(), start.end(), t) - start.begin();
            int dead = lower_bound(end.begin(), end.end(), t) - end.begin();
            ans.push_back(bloomed - dead);
        }

        return ans;
    }
};