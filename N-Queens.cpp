class Solution {
public:
    void addSolution(vector<vector<string>> &ans, vector<vector<int>> &board, int n) {
        //in this, we define a string for each row, and in that we explain the configuration of each queen and black square. Total n rows.
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string row = "";
            for (int j = 0; j < n; j++) {
                row += (board[i][j] == 1) ? "Q" : ".";
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
        //in this function , we check if it is safe to place a queen at a particular column in a certain row.

        for (int i = 0; i < col; i++) {
            if (board[row][i] == 1) {
                return false;
            }
        }
        
        //checking for each diagonal , first here we are looking at diagonally up-backwards
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }
        //in this loop , we are looking at diagonally down backwards from current position.
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 1) {
                return false;
            }
        }

        return true;
    }

    void solve(int col, vector<vector<string>> &ans, vector<vector<int>> &board, int n) {
        if (col == n) {
            //we have reached one of the solutions. 
            addSolution(ans, board, n);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 1;
                solve(col + 1, ans, board, n);
                board[row][col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        solve(0, ans, board, n);
        return ans;
    }
};
