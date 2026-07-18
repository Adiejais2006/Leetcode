// Last updated: 7/18/2026, 1:59:51 PM
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto it : nums)
            mpp[it]++;
        int ans = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x == 1) {
                if (mpp[x] % 2 == 0) {
                    ans = max(ans, mpp[x] - 1);
                } else
                    ans = max(ans, mpp[x]);
            } else {
                int cnt = 0;
                if (mpp[x] > 1) {
                    long long curr = x;
                    while (curr <= INT_MAX &&
                           mpp.find((int)curr) != mpp.end()) {
                        if (mpp[(int)curr] == 1) {
                            cnt++;
                            break;
                        }
                        cnt++;
                        if (curr > LLONG_MAX / curr)
                            break;
                        curr *= curr;
                    }
                }
                ans = max(ans, cnt * 2 - 1);
            }
        }

        return ans;
    }
};