// Last updated: 7/18/2026, 2:04:36 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int cnt = 0;
        int n = s.size();
        unordered_map<int, int> mpp;
        while (r < n) {
            mpp[s[r]]++;
            cnt = max(cnt, mpp[s[r]]);
            if ((r - l + 1) - cnt > k) {
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};