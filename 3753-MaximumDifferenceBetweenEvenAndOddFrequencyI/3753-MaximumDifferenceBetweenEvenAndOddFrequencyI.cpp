// Last updated: 7/18/2026, 1:59:33 PM
class Solution {
public:
    int maxDifference(string s) {
        vector<int> mpp(26, 0);
        for (int i = 0; i < s.length(); i++) {
            mpp[s[i] - 'a']++;
        }
        int ans = INT_MIN;
        for (int i = 0; i < 26; i++) {
            if (mpp[i] == 0)
                continue;
            for (int j = 0; j < 26; j++) {
                if (mpp[j] == 0)
                    continue;
                if ((mpp[i] % 2 == 1 && mpp[j] % 2 == 0)) {
                    ans = max(ans, mpp[i] - mpp[j]);
                }
            }
        }
        return ans;
    }
};