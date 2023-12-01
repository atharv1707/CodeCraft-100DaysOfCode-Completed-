#include <vector>

class Solution {
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0 ; ; i < rows ; i++){
            for(int j = 0 ; j  < cols; j++){
                if(i > 0 && j > 0 && matrix[i][j] != matrix[i-1][matrix[j-1]]){
                    return false;
                }
            }
        }

        return true;
    }
};
