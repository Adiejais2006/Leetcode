// Last updated: 7/18/2026, 1:58:55 PM
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> ze, onee, twoo;

        for (int i = 0; i < nums.size(); i++) {
            int r = nums[i] % 3;
            if (r == 0) ze.push_back(nums[i]);
            else if (r == 1) onee.push_back(nums[i]);
            else twoo.push_back(nums[i]);
        }

        sort(ze.begin(), ze.end());
        sort(onee.begin(), onee.end());
        sort(twoo.begin(), twoo.end());

        int ans = 0;

        if (ze.size() >= 3) {
            int s = ze.back() + ze[ze.size() - 2] + ze[ze.size() - 3];
            ans = max(ans, s);
        }

        if (onee.size() >= 3) {
            int s = onee.back() + onee[onee.size() - 2] + onee[onee.size() - 3];
            ans = max(ans, s);
        }

        if (twoo.size() >= 3) {
            int s = twoo.back() + twoo[twoo.size() - 2] + twoo[twoo.size() - 3];
            ans = max(ans, s);
        }

        if (!ze.empty() && !onee.empty() && !twoo.empty()) {
            int s = ze.back() + onee.back() + twoo.back();
            ans = max(ans, s);
        }

        return ans;
    }
};
