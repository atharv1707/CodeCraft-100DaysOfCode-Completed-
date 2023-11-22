class Solution {
public:
    bool isUglyNumber(int i){
        while(i>1){
            if(i %2 == 0){
                i /=2;
            }
            else if(i % 3 == 0){
                i /= 3;
            }
            else if(i % 5 == 0){
                i /= 5;
            }
            else{
                return false;
            }     
        }
        return true;
    }

    int nthUglyNumber(int n) {

        vector<int> store;
        store.push_back(1);
        int i = 2;

        while(store.size() < n){
            if(isUglyNumber(i)){
                store.push_back(i);
            }

            i++;

        }

        return store.back();

        
    }
};


//approach 2 

//the logic is that all such numbers can be written in exp(2,3,5)^x where x is whole number. So you track whose increase in exponent gave us a ugly number and basically increase that to look for the next one. Good luck!



class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> store;

        int i2;
        int i3;
        int i5;

        i2 = i3 = i5 = 0 ; 
        store.push_back(1);

        while(store.size() < n){
            int nextUgly = min({store[i2]*2, store[i3]*3, store[i5]*5});
            store.push_back(nextUgly);

            if(nextUgly == store[i2]*2 ){
                i2++;
            }
            
            if(nextUgly == store[i3]*3){
                i3++;
            }

            
            if(nextUgly == store[i5]*5 ){
                i5++;
            }
        }

        return store.back();
        
        
        
    }
};
