// Last updated: 7/18/2026, 2:02:50 PM
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int sum = 0;
        int ans = 0;
        int n = nums.size();
        mpp[0] = 1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int r = (sum % k + k) % k;

            if (mpp.find(r) != mpp.end()) {
                ans += mpp[r];
            }

            mpp[r]++;
        }
        return ans;
    }
};