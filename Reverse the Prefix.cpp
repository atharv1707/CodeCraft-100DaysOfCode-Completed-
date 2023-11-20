class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        int target_index = word.find(ch);

        if(target_index != string::npos){
            reverse(word.begin(), word.begin()+target_index+1);
        }

        return word;




        
    }
};