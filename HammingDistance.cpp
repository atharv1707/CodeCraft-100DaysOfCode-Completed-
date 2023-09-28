// Solution 0 : 

// class Solution {
// public:
//     int hammingDistance(int x, int y) {

//          int a  = __builtin_popcount(x^y); //using builtin function which count number of set bits (number of 1s in the binary representation of the number )
//         return a;
        
//     }
// };



class Solution {
public:
    int hammingDistance(int x, int y) {

        int res = x^y;
        int count = 0 ; 

         while(res > 0){
             //checking least sig bit of the res
             if(res & 1){
                 count ++;
             }

             res >>= 1;

         }
         return count;

        
    }
};
