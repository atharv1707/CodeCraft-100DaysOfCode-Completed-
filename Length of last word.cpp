class Solution {
public:
    int lengthOfLastWord(string s) {
        int wordlen = 0;
        reverse(s.begin(), s.end());

        for(int i = 0; i<s.size() ; i++){
            if(s[i] !=' '){
                wordlen++; 
                if(s[i+1] == ' '){
                    if(wordlen>0){
                    break;
                    }
                }
            }
        }
        return wordlen;
    }
};