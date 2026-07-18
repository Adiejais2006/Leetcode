// Last updated: 7/18/2026, 2:07:11 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin() , arr.end());
        for (auto it : arr) {
            if (ans.empty() || ans.back()[1] + 1 <= it[0])
                ans.push_back(it);
            else {
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }

        return ans;
    }
};