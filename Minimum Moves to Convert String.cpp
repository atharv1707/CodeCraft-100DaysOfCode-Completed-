class Solution {
public:
    int minimumMoves(string s) {
        int count = 0 ; 

        int i = 0 ; 
        int N = s.length();
        while( i < N){
            
            if(s[i] == 'X'){
                count++;
                i += 3;
                continue;
            }
            i++;
        }

        return count;
        
    }
};