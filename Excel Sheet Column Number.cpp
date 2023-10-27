// the only thing to keep in mind is it is a 26 based system not 10-based.

class Solution {
public:
    int titleToNumber(string s) {

        int size = s.size();
        int i = size;
        int res;
        int n = 0 ; 

        while(i--){

            res += pow(26,n) * (s[i] - 64);
            n ++;

        }
        return res;

        
    }
};