class Solution {
public:
    int findComplement(int num) {

        int ans = 0 ; 
        int i = 0 ; 

        while(num){
            int bit = num & 1; //calculating LSB
            bit = (bit==1) ? 0 : 1 ;
            ans |= (bit << i); 
            num >>=1;
            i++;
        }

        return ans;
        
    }
};