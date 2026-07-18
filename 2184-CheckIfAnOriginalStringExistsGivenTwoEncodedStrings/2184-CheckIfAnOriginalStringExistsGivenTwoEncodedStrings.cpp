// Last updated: 7/18/2026, 2:01:05 PM
class Solution {
public:
    bool possiblyEquals(string s1, string s2) {
        bool memo[41][41][2000];
        memset(memo, false, sizeof(memo));
        return check(0, 0, 0, s1, s2, memo);
    }

private:
    bool check(int i, int j, int diff, string& s1, string& s2, bool memo[41][41][2000]) {
        if (i == s1.size() && j == s2.size()) return diff == 0;
        if (memo[i][j][diff + 1000]) return false;
        memo[i][j][diff + 1000] = true;

        if (i < s1.size() && isdigit(s1[i])) {
            int val = 0;
            for (int k = i; k < s1.size() && isdigit(s1[k]); ++k) {
                val = val * 10 + (s1[k] - '0');
                if (check(k + 1, j, diff + val, s1, s2, memo)) return true;
            }
            return false;
        }

        if (j < s2.size() && isdigit(s2[j])) {
            int val = 0;
            for (int k = j; k < s2.size() && isdigit(s2[k]); ++k) {
                val = val * 10 + (s2[k] - '0');
                if (check(i, k + 1, diff - val, s1, s2, memo)) return true;
            }
            return false;
        }

        if (diff > 0 && j < s2.size() && isalpha(s2[j])) {
            return check(i, j + 1, diff - 1, s1, s2, memo);
        }
        if (diff < 0 && i < s1.size() && isalpha(s1[i])) {
            return check(i + 1, j, diff + 1, s1, s2, memo);
        }
        if (diff == 0 && i < s1.size() && j < s2.size() && s1[i] == s2[j]) {
            return check(i + 1, j + 1, 0, s1, s2, memo);
        }

        return false;
    }
};