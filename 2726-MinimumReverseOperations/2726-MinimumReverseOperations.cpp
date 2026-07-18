// Last updated: 7/18/2026, 2:00:16 PM
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<int> ans(n, -1);
        vector<bool> ban(n, false);

        for (int x : banned) ban[x] = true;

        set<int> st[2];
        for (int i = 0; i < n; i++) {
            if (i != p && !ban[i]) st[i & 1].insert(i);
        }

        queue<int> q;
        q.push(p);
        ans[p] = 0;

        while (!q.empty()) {
            int x = q.front();
            q.pop();

            int lo = max(0, x - k + 1);
            int hi = min(x, n - k);

            int L = 2 * lo + k - 1 - x;
            int R = 2 * hi + k - 1 - x;

            auto& s = st[L & 1];
            auto it = s.lower_bound(L);

            while (it != s.end() && *it <= R) {
                int y = *it;
                ans[y] = ans[x] + 1;
                q.push(y);
                it = s.erase(it);
            }
        }

        return ans;
    }
};