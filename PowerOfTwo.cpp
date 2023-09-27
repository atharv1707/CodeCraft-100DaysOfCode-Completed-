class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<= 0 ){
            return false;
        }

        int res = n & (n-1);
        
        return ( res == 0 ) ;
        //all 2's powers have 1 and nth postion (n-> power) , thus and operator in n and n-1 gives us 0 if the n is power of 2 at n. 
        
    }
};