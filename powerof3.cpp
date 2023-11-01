class Solution {
public:

    bool check(int n){

        if(n == 1){
            return true;
        }
        if(n <= 0){
            return false;
        }
        if(n%3 == 0){
            n /= 3;
            return check(n);
        }
        else{
            return false;
        }
    }
    bool isPowerOfThree(int n) {

       if(n<= 0){
           return false;
       }

       return check(n);
        
    }
};