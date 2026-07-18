// Last updated: 7/18/2026, 2:03:05 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
          int n = fruits.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[fruits[r]]++;
            if (mpp.size() > 2) {
                if (mpp.size() > 2) {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0) mpp.erase(fruits[l]);
                    l++;
                }
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};