class Solution {
public:
    bool isSafe(int newx, int newy, vector<vector<bool>>& visited, vector<vector<int>>& m, int n) {
        // Check if it is safe to move to the next cell based on three conditions:
        // 1) The cell should be within the bounds of the maze.
        // 2) The cell should be unvisited.
        // 3) The cell should have a value of 1.
        if (newx >= 0 && newx < n && newy >= 0 && newy < n && !visited[newx][newy] && m[newx][newy] == 1) {
            return true;
        }
        return false;
    }

    void solve(int x, int y, vector<string>& res, vector<vector<int>>& m, int n, vector<vector<bool>>& visited, string path) {
        // Base case: If the rat has reached the destination, add the path to the result.
        if (x == n - 1 && y == n - 1) {
            res.push_back(path);
            return;
        }

        // Mark the current cell as visited.
        visited[x][y] = true;

        // DOWN
        if (isSafe(x + 1, y, visited, m, n)) {
            solve(x + 1, y, res, m, n, visited, path + 'D');
        }

        // LEFT
        if (isSafe(x, y - 1, visited, m, n)) {
            solve(x, y - 1, res, m, n, visited, path + 'L');
        }

        // RIGHT
        if (isSafe(x, y + 1, visited, m, n)) {
            solve(x, y + 1, res, m, n, visited, path + 'R');
        }

        // UP
        if (isSafe(x - 1, y, visited, m, n)) {
            solve(x - 1, y, res, m, n, visited, path + 'U');
        }

        // Backtrack by marking the current cell as unvisited.
        visited[x][y] = false; 
    }

    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> res;
        vector<vector<bool> > visited(n, vector<bool>(n, false)); // Initialize the visited matrix.
        string path = "";

        if (m[0][0] == 0) {
            return res; // Return an empty result if the source cell is blocked.
        }

        solve(0, 0, res, m, n, visited, path); // Start solving from the source (0,0).
        return res;
    }
};