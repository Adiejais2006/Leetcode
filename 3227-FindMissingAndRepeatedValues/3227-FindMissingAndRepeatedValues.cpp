// Last updated: 7/18/2026, 1:59:53 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        long long n = nums.size();
        long long total = n * n;   // numbers are from 1 to n^2

        long long ns = (total * (total + 1)) / 2;
        long long nsos = (total * (total + 1) * (2 * total + 1)) / 6;

        long long s = 0, p = 0;

        for (long long i = 0; i < n; i++) {
            for (long long j = 0; j < n; j++) {
                s += nums[i][j];
                p += 1LL * nums[i][j] * nums[i][j];
            }
        }

        // repeat - missing
        long long eq1 = s - ns;

        // repeat^2 - missing^2
        long long eq2 = p - nsos;

        // repeat + missing
        long long eq3 = eq2 / eq1;

        long long repeat = (eq1 + eq3) / 2;
        long long missing = eq3 - repeat;

        return {(int)repeat, (int)missing};
    }
};