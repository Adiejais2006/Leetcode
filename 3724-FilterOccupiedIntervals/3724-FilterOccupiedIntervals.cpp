// Last updated: 7/18/2026, 1:59:34 PM
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& arr,
                                                int freeStart, int freeEnd) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> temp;
        for (auto it : arr) {
            if (temp.empty() || temp.back()[1] + 1 < it[0])
                temp.push_back(it);
            else {
                temp.back()[1] = max(temp.back()[1], it[1]);
            }
        }
        vector<vector<int>> ans;
        for (auto it : temp) {
            if (it[1] < freeStart || it[0] > freeEnd) {
                ans.push_back(it);
            } else if (it[0] < freeStart && it[1] <= freeEnd) {
                ans.push_back({it[0], freeStart - 1});
            } else if (it[0] >= freeStart && it[1] > freeEnd) {
                ans.push_back({freeEnd + 1, it[1]});
            } else if (it[0] < freeStart && it[1] > freeEnd) {
                ans.push_back({it[0], freeStart - 1});
                ans.push_back({freeEnd + 1, it[1]});
            }
            
        }

        return ans;
    }
};