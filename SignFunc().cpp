class Solution {
public:
    int arraySign(vector<int>& nums) {

        int sign = -1;
        int negs = 0;

        for(int i : nums){
            if(i == 0){
                int sign = 0 ; 
                return sign;
                
            }
            if(i < 0){
                negs++;
            }
        }

        if(negs %2 == 0){
            sign = 1;

        }
        else{
            sign = -1;
        }
        



        return sign ;
        
    }
};