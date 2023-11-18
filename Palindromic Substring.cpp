class Solution {
public:
    bool checkString(string s, int i , int j){

        while(i<=j){
            if(s[i] == s[j]){
            i++;
            j--;
            }
            else{
                return false;
            }
        }

        return true;
    }
    int countSubstrings(string s) {
        int n = 0 ; 
        int len = s.length();

        for(int i = 0 ; i < len ; i ++){
            for(int j = i ; j < len ; j++){
                if(checkString(s, i,j)){
                    n++;
                }
            }
        }

        return n;
        
    }
};