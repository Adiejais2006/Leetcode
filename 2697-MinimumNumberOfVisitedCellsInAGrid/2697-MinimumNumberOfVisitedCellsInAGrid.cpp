// Last updated: 7/18/2026, 2:00:22 PM
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<set<int>> rows(m), cols(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i].insert(j);
                cols[j].insert(i);
            }
        }

        queue<array<int, 3>> q;
        q.push({0, 0, 1});

        rows[0].erase(0);
        cols[0].erase(0);

        while (!q.empty()) {
            auto [r, c, d] = q.front();
            q.pop();

            if (r == m - 1 && c == n - 1) return d;

            auto it = rows[r].upper_bound(c);

            while (it != rows[r].end() && *it <= c + grid[r][c]) {
                int nc = *it;
                q.push({r, nc, d + 1});

                cols[nc].erase(r);
                it = rows[r].erase(it);
            }

            it = cols[c].upper_bound(r);

            while (it != cols[c].end() && *it <= r + grid[r][c]) {
                int nr = *it;
                q.push({nr, c, d + 1});

                rows[nr].erase(c);
                it = cols[c].erase(it);
            }
        }

        return -1;
    }
};