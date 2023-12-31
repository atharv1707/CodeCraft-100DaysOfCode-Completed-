// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/


class Solution {
public:
    int minFlips(int a, int b, int c) {

        int flip_count = 0; 
        

        while(a > 0 || b > 0 || c > 0){

            //here we take each LSB from the numbers.
            int lsb1 = a&1;
            int lsb2 = b&1;
            int lsb3 = c&1;

            //there will be essentially three cases to write to cover all the scenarios where we increase the count. Just write it down. 

            if((lsb1 == 1 && lsb2 == 1) && lsb3 == 0){
                flip_count += 2;
            }
            else if((lsb1 == 1 || lsb2 == 1) && lsb3 == 0){
                flip_count++;
            }
            else if((lsb3 == 1) && (lsb1 == 0 && lsb2 == 0)){
                flip_count++;
            }

            //Right shift the number to make get the new LSB

            a >>=1;
            b >>=1;
            c >>=1;


        }

        return flip_count;
        
    }
};