//we notice that both are interdependent via c

class Solution {
public:
    bool judgeSquareSum(int c) {

        if(c == 0){
            return true;
        }

        for(int i = 0 ; i < sqrt(c) ; i++){
            int j = sqrt(c- i*i); // b^2 = c - a^2;
            if(i*i + j*j == c){
                return true;
            }

        }

        return false;
        
    }
};

//two-pointer search.
//I guess I should start using long long in general hehe

class Solution {
public:
    bool judgeSquareSum(int c) {

        long s = 0 ; 
        long e = sqrt(c);
        long long sum = 0 ; 

        while(s <= e){
            
            sum = s*s + e*e;
            if(sum ==c){
                return true;
            }

            else if(sum > c){
                e--;
            }
            
            else{
                s++;
            }
        }

        return false;
        
    }
};

