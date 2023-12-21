class Solution {
public:
    int convertToInteger(string& str){
        int result = 0 ; 

        for(char c : str){
            result = result *10 + (c-'a');

        }

        return result;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {

        int result1 = convertToInteger(firstWord);
        int result2 = convertToInteger(secondWord);
        int target = convertToInteger(targetWord);

        return target == result1 + result2;        
        
    }
};