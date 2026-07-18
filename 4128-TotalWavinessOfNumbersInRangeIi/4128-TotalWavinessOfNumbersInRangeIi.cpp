// Last updated: 7/18/2026, 1:59:02 PM
class Solution {
private:
    long long memo[16][11][11][2][2][2];
    long long count_memo[16][11][11][2][2][2];
    string num_str;

    pair<long long, long long> dp(int idx, int prev1, int prev2, bool is_tight, bool is_zero) {
        if (idx == num_str.length()) {
            return {1, 0};
        }

        int p1_idx = prev1 == -1 ? 10 : prev1;
        int p2_idx = prev2 == -1 ? 10 : prev2;

        if (memo[idx][p1_idx][p2_idx][is_tight][is_zero][0] != -1) {
            return {count_memo[idx][p1_idx][p2_idx][is_tight][is_zero][0], 
                    memo[idx][p1_idx][p2_idx][is_tight][is_zero][0]};
        }

        long long total_count = 0;
        long long total_waviness = 0;
        int limit = is_tight ? (num_str[idx] - '0') : 9;

        for (int d = 0; d <= limit; ++d) {
            bool next_tight = is_tight && (d == limit);
            bool next_zero = is_zero && (d == 0);
            
            int next_prev1 = next_zero ? -1 : d;
            int next_prev2 = prev1;

            auto [ways, waviness] = dp(idx + 1, next_prev1, next_prev2, next_tight, next_zero);
            
            total_count += ways;
            total_waviness += waviness;

            if (!is_zero && prev2 != -1) {
                if ((prev1 > prev2 && prev1 > d) || (prev1 < prev2 && prev1 < d)) {
                    total_waviness += ways;
                }
            }
        }

        count_memo[idx][p1_idx][p2_idx][is_tight][is_zero][0] = total_count;
        return {total_count, memo[idx][p1_idx][p2_idx][is_tight][is_zero][0] = total_waviness};
    }

    long long solve(long long n) {
        if (n < 100) {
            return 0;
        }
        num_str = to_string(n);
        memset(memo, -1, sizeof(memo));
        memset(count_memo, -1, sizeof(count_memo));
        return dp(0, -1, -1, true, true).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};