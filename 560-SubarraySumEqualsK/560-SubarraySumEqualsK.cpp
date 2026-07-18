// Last updated: 7/18/2026, 2:04:01 PM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        mpp[0] = 1;
        int n = nums.size();
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = -k + sum;
            if (mpp.find(rem) != mpp.end()) {
                ans += mpp[rem];
            }
            mpp[sum]++;
        }
        return ans;
    }
};