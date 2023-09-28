class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned int rb = 0;

        for(int i = 0 ; i < 32 ; i ++){

            //we shift right the original number and left shift the building answer. 
            //you check the least significant bit of n, by & operator with 1. 
            //You start building the answer by for each bit in input integer, we shift the rb << 1, using OR with it with lb. 
            //Atlast, we update the n >>=1 . Run this iteration 32 times because it's a 32 bit unsigned integer. 
            //I guess that makes some sense. Try 32 times again hehe. 
            unsigned int lb = n & 1;
            rb = (rb<<1) | (lb);
            n >>= 1;
            
        }

        return rb;


        
    }
};