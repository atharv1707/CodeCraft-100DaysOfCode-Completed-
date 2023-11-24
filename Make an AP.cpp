#include <vector>
#include <algorithm>

class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int n = arr.size();

        if (n == 2) {
            return true;
        }

        int cd = arr[1] - arr[0];
        int a = arr.front();

        for (int i = 1; i < n; i++) {
            if (arr[i] != a + (i) * cd) {
                return false;
            }
        }

        return true;
    }
};


//similar appraoch but less better

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        vector<int> Copy(arr.begin(), arr.end());
        sort(Copy.begin(), Copy.end());
        int n = arr.size();
        int cd = Copy[1] - Copy[0]; 
        int a = Copy.front();
        vector<int> test;
        
        if(n==2){
            return true;
        }
        
        for(int i = 1; i <= n; i++){
            test.push_back((a + (i-1) * cd));
        }

        return test == Copy;
    }
};

