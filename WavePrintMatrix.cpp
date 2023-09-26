
//My approach :  The main logic was ,  to  column-wise print the matrix, and then reverse the those columns at odd indexes. Think about it!
//Because we are storing the result in a linear array, we traverse and if we find the column odd, we append it's element reverse to the RESULT, else we are fine with appending the column elements like we encounter them. 


#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>>& arr, int nRows, int mCols) {
    vector<int> result;

    for (int j = 0; j < mCols; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < nRows; i++) {
                result.push_back(arr[i][j]);
            }
        } else {
            for (int i = nRows - 1; i >= 0; i--) {
                result.push_back(arr[i][j]);
            }
        }
    }

    return result;
}


