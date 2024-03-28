//brute force

class Solution {
  public:
  
    bool check(int X){
        string num = to_string(X);
        int n = num.length();
        
        for(int i = 1 ; i < n-1;i++){
            int curr = num[i] - '0';
            int prev = num[i-1] - '0';
            if(abs(curr-prev) != 1){
                return false;
                
            } 
        }
        
        return true;
    }
    long long jumpingNums(long long X) {
        
        
        
        bool found = false;
        
        while(!found && X ){
            if(check(X)){
                found = true;
            }
            else{
                X--;
            }
        }
        
        return X;
    }
};

//recursion

class Solution {
  public:
    void rec(long long num, int x, long long& val){
        
        if(num > x){
            return;
        }
        
        val = max(val, num);
        
        int add = num%10+1;
        int sub = num%10-1;
        
        //keep building number on the prev numbers
        if(add < 10){
            rec(num*10 + add, x, val);
        }
        if(sub >= 0){
            rec(num*10 + sub, x, val);
        }
    }
    long long jumpingNums(long long x) {
        // code here
        
        long long ans = 1;
        for(int i = 1;i < 10 ; i++){
            rec(i, x, ans, found);
        }
        
        return ans;
    }
