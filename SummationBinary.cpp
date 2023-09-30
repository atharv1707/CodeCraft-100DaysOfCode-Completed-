class Solution {
public:
    int getSum(int a, int b) {

        int sum = 0 ;
        int carry = 0 ; 

        while(b){

            sum =  a ^ b; // taking sum wihtout considering sum
            carry = (a & b ) << 1; //taking carry if both bits are 1
            a = sum; //return this because when b reaches 0 , our final sum is stored in the a.
            b  = carry;
        }

        return a;
        
    }
};