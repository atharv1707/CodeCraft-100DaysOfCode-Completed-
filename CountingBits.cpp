class Solution {
public:

//when we use bitwise operator, wethe number are impplicitly converted to their binary representation. Keep that in mind! You can be given with integer or binary rep. 

    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count  += n&1;
            n >>= 1;
        }

        return count;
        
    }
};
