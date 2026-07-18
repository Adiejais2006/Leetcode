// Last updated: 7/18/2026, 2:04:08 PM
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        int sum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (mpp.find(sum) != mpp.end()) {
                len = max(len, i - mpp[sum] );
            }

            if (mpp.find(sum) == mpp.end())
                mpp[sum] = i;
        }

        return len;
    }
};