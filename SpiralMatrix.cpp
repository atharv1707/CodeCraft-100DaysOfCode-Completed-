class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans; 

        int row = matrix.size();
        if (row == 0)
            return ans;  // Return empty vector for empty matrix

        int col = matrix[0].size();

        int SR = 0, SC = 0, ER = row - 1, EC = col - 1;
        int count = 0, total = row * col;

        while (count < total) {
            // Print SR
            for (int index = SC; count < total && index <= EC; index++) {
                ans.push_back(matrix[SR][index]);
                count++;
            }
            SR++;

            // Print EC
            for (int index = SR; count < total && index <= ER; index++) {
                ans.push_back(matrix[index][EC]);
                count++;
            }
            EC--;

            // Print ER
            for (int index = EC; count < total && index >= SC; index--) {
                ans.push_back(matrix[ER][index]);
                count++;
            }
            ER--;

            // Print SC
            for (int index = ER; count < total && index >= SR; index--) {
                ans.push_back(matrix[index][SC]);
                count++;
            }
            SC++;
        }

        return ans;
    }
};
