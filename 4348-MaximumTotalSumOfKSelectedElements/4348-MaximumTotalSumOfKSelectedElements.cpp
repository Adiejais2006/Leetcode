// Last updated: 7/18/2026, 1:58:27 PM
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end());
        long long n = nums.size();
        long long ans = 0;
        long long i = n - 1;

        while (k > 0) {
            ans += max((long long)nums[i], (long long)mul * (long long)nums[i]);
            mul--;
            k--;
            i--;
        }

        return ans;
    }
};