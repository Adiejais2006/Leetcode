// Last updated: 7/18/2026, 1:58:36 PM
class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {

        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            long long sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum % 10 != x)
                    continue;
                 long long orig = sum;
                while (orig >= 10)
                    orig /= 10;
                if (orig == x)
                    cnt++;
            }
        }
        return cnt;
    }
};