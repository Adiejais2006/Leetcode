// Last updated: 7/18/2026, 1:58:32 PM
class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> d(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);
                d[l]++;
                d[r + 1]--;
            }
        }
        vector<int> ok(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += d[i];
            if (cnt > 0)
                ok[i] = 1;
        }
        int ans = 0;
        int i = 0;
        while (i < n) {
            if (ok[i]) {
                i++;
            } else {
                ans++;
                i += 3;
            }
        }
        return ans;
    }
};