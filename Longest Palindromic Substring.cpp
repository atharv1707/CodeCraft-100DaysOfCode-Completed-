class Solution {
public:
    int t[1001][1001];
    bool checkStr(int i, int j, string &str){
        if(i >= j){
            return 1;
        }

        if(t[i][j] != -1){
            return t[i][j];
        }

        else if(str[i] == str[j]){
            return t[i][j] = checkStr(i+1,j-1, str);
        }
        else{
            return t[i][j] = 0;
        }


    }
    string longestPalindrome(string s) {
        memset(t,-1,sizeof(t));
        int maxLen = 0 ;
        int start = 0;


        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i; j < s.size() ; j++){
                if(checkStr(i,j,s)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        start = i;
                    }
                }
            }
        }


        return s.substr(start, maxLen);

        
    }
};