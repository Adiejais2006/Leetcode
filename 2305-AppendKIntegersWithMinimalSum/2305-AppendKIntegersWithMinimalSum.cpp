// Last updated: 7/18/2026, 2:00:52 PM
class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        long long ans = 0;
        long long cur = 1;

        for (int x : nums) {
            if (cur < x) {
                long long take = min((long long)k, (long long)x - cur);
                ans += (cur + cur + take - 1) * take / 2;
                k -= take;
            }

            cur = max(cur, (long long)x + 1);

            if (k == 0) break;
        }

        if (k > 0) {
            ans += (cur + cur + k - 1LL) * k / 2;
        }

        return ans;
    }
};