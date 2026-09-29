// Last updated: 9/29/2026, 7:09:57 PM
1class Solution {
2public:
3    bool hasValidPath(vector<vector<char>>& grid) {
4        int m = grid.size();
5        int n = grid[0].size();
6        int length = m + n - 1;
7
8        if (length % 2 != 0 || grid[0][0] != '(' ||
9            grid[m - 1][n - 1] != ')') {
10            return false;
11        }
12
13        // -1: unknown, 0: false, 1: true
14        vector<vector<vector<int8_t>>> memo(
15            m, vector<vector<int8_t>>(
16                   n, vector<int8_t>(length + 1, -1)));
17
18        function<bool(int, int, int)> dfs = [&](int row, int col,
19                                                  int balance) -> bool {
20            balance += (grid[row][col] == '(' ? 1 : -1);
21            int remaining = (m - 1 - row) + (n - 1 - col);
22
23            if (balance < 0 || balance > remaining) return false;
24            if (row == m - 1 && col == n - 1) return balance == 0;
25
26            int8_t& cached = memo[row][col][balance];
27            if (cached != -1) return cached == 1;
28
29            bool possible =
30                (row + 1 < m && dfs(row + 1, col, balance)) ||
31                (col + 1 < n && dfs(row, col + 1, balance));
32
33            cached = possible ? 1 : 0;
34            return possible;
35        };
36
37        return dfs(0, 0, 0);
38    }
39};