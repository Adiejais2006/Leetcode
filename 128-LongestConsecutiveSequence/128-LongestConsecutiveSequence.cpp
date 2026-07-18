// Last updated: 7/18/2026, 2:06:13 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int> mpp(nums.begin(), nums.end());
        int ans = 0;
        for (auto it : mpp) {
            int el = it;
            int cnt = 0;
            if (mpp.find(it + 1) == mpp.end()) {
                while (mpp.find(el) != mpp.end()) {
                    cnt++;
                    el--;
                }
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};