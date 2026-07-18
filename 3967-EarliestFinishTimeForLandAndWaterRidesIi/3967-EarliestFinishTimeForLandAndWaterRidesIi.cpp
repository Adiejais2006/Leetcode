// Last updated: 7/18/2026, 1:59:15 PM
class Solution {
public:
    int calc(vector<int>& s1, vector<int>& d1, vector<int>& s2,
             vector<int>& d2) {
        int minEnd = INT_MAX;

        for (int i = 0; i < s1.size(); i++) {
            minEnd = min(minEnd, s1[i] + d1[i]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < s2.size(); i++) {
            ans = min(ans, max(minEnd, s2[i]) + d2[i]);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int a =
            calc(landStartTime, landDuration, waterStartTime, waterDuration);

        int b =
            calc(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(a, b);
    }
};
