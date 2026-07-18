// Last updated: 7/18/2026, 2:05:28 PM
class Solution {  void func(int ind, int sum, vector<int> &temp, vector<vector<int>> &ans,
              int k) {
        if (sum == 0 && temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        if (sum < 0 || temp.size() > k || ind > 9) {
            return;
        }
            // not pickc
        func(ind + 1, sum, temp, ans, k);
        // pick
        temp.push_back(ind);
        func(ind + 1, sum - ind, temp, ans, k);
        temp.pop_back();
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> ans;
        vector<int> temp;
        func(1, n, temp, ans, k);
        return ans;
    }
};