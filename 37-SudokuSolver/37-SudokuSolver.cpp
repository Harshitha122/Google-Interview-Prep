class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            // Check row, column, and 3x3 sub-grid
            if (board[row][i] == num || 
                board[i][col] == num || 
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
                return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {  // Attempt to fill an empty cell
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;  // Place the number
                            if (solve(board)) {
                                return true;  // If it solves, return true
                            }
                            board[i][j] = '.';  // Backtrack if needed
                        }
                    }
                    return false;  // Return false if no valid number found
                }
            }
        }
        return true;  // Return true if solved
    }
};
