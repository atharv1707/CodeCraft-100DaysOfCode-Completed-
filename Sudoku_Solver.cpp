//we create a solve function . There we have 2 loops, to iterate to each block, inside which we have third we checkst the empty space . Then we call isSafe function to check which number we can insert in the empty space as per rules and that's it. We fill it , go through all blocks, and repeat the same. 

class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char k) {
        for (int i = 0; i < board.size(); i++) {
            // Checking the row
            if (board[row][i] == k) {
                return false;
            }
            // Checking the column
            if (board[i][col] == k) {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k) {
                // Checking in the 3x3 grid inside the Sudoku board
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (isSafe(i, j, board, k)) {
                            board[i][j] = k;

                            bool solutionFound = solve(board);
                            if (solutionFound) {
                                return true;
                            } else {
                                // Backtrack because solution is not possible
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
