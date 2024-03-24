class Solution{
    public:
    vector<vector<int>> visited;
    
    void solve(vector<vector<int>>& m, int row, int col, int n, const string& path, vector<string>& paths){
        
        //base case for the recursion
        
        if(row < 0 || row >=n || col < 0 || col >=n || m[row][col] == 0 || visited[row][col]){
            return;
        }
        
        // if we reach here that means it is a safe cell to continue
        visited[row][col] = 1;
        
        if(row == n-1 && col == n-1){
            paths.push_back(path);
            visited[row][col] = 0;
            return;
        }
        
        
        //now check for up, down, left and right direction
        
        solve(m, row-1, col, n, path + 'U', paths); //down
        solve(m, row+1, col, n, path + 'D', paths); //up
        solve(m, row, col-1, n, path + 'L', paths); //left
        solve(m, row, col+1, n, path + 'R', paths);//right
        
        //when all directions are traversed, make sure to 
        
        visited[row][col] = 0;

        
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        visited = vector<vector<int>>(n, vector<int>(n, 0));

        string path = "";
        vector<string> paths;
        int row = 0;
        int col = 0;
        solve(m, row, col, n, path, paths);
        
        return paths;
        
        
    }
};
