// Last updated: 7/18/2026, 2:02:23 PM
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();

        vector<vector<int>> score(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> ways(n + 1, vector<int>(n + 1, 0));

        score[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;

        int dx[3] = {1, 0, 1};
        int dy[3] = {0, 1, 1};

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (board[i][j] == 'X' || board[i][j] == 'S')
                    continue;

                for (int k = 0; k < 3; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];

                    if (score[x][y] == -1)
                        continue;

                    if (score[x][y] > score[i][j]) {
                        score[i][j] = score[x][y];
                        ways[i][j] = ways[x][y];
                    } 
                    else if (score[x][y] == score[i][j]) {
                        ways[i][j] = (ways[i][j] + ways[x][y]) % MOD;
                    }
                }

                if (score[i][j] != -1 && board[i][j] != 'E') {
                    score[i][j] += board[i][j] - '0';
                }
            }
        }

        if (score[0][0] == -1)
            return {0, 0};

        return {score[0][0], ways[0][0]};
    }
};