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


