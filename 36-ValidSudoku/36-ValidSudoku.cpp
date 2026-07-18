// Last updated: 7/18/2026, 2:07:31 PM
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}; // rowno ,  val
        bool col[9][9] = {false}; // colno , val
        bool box[9][9] = {false}; // konsa box hai aur konsi value hai us box me
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxindx =
                        (i / 3) * 3 +
                        (j / 3); // badically 9 boxes me se batat hai konsa hia
                    if (row[i][num] || col[j][num] || box[boxindx][num])
                        return false;
                    row[i][num] = col[j][num] = box[boxindx][num] = true;
                }
            }
        }

        return true;
    }
};