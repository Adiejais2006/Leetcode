// Last updated: 7/18/2026, 2:07:30 PM
class Solution {bool check(char no, vector<vector<char>> &board, int row, int col) {
        int r = row;
        int c = col;
        int n = 9;
        for (int i = 0; i < n; i++) {
            if(no == board[i][col] || no == board[row][i]) return false;
        }
        
        int startrow = (row /3)* 3;
        int startcol = (col/3)*3;

        for(int i = startrow ; i<startrow + 3 ; i++){
            for(int j = startcol ; j <startcol +3 ;j++){
                if(board[i][j]==no) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == '.') {
                    for (char x = '1'; x <= '9'; x++) {
                        if (check(x, board, i, j)) {
                            board[i][j] = x;
                            bool vall = solve(board);
                            if (vall) return true;
                            board[i][j] = '.';
                        }
                    }
                return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};