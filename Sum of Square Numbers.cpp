class Solution {
public:
    bool judgeSquareSum(int c) {

        if(c == 0){
            return true;
        }

        for(int i = 0 ; i < sqrt(c) ; i++){
            int j = sqrt(c- i*i); // b^2 = c - a^2;
            if(i*i + j*j == c){
                return true;
            }

        }

        return false;
        
    }
};