// Last updated: 7/18/2026, 2:06:23 PM
class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> ans(r + 1);

        ans[0] = 1;

        for(int i = 1; i <= r; i++) {
            ans[i] = (1LL * ans[i - 1] * (r - i + 1)) / i;
        }

        return ans;
    }
};