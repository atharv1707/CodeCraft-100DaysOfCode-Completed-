class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int row = grid.size();
        int cols = grid[0].size();
        int count  = 0 ; 

        for(int i = 0 ; i < row ; i++){
            int start = 0 ; 
            int end = cols-1;
            while(start <= end){
                int mid = start + (end-start)/2;
                if(grid[i][mid] >= 0){
                    start = mid +1;
                }
                else{
                    count += (end-mid +1);
                    end = mid-1;
                }
            }
        }

        return count;

        
    }
};