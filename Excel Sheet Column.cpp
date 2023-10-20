class Solution {
public:
    string convertToTitle(int CN) {

        string res = "";

        while(CN>0){
            char lastDig = (CN-1)%26+'A';//mapping starts from 1 here, thus minus 1
            res = lastDig + res;//build the answer.
            CN = (CN-1)/26; //mapping starts from 1 here, thus minus 1
        }

        return res;
        
    }
};