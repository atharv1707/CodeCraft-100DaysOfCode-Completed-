class Solution {
public:
    string reverseOnlyLetters(string s) {
        string result ="";
        stack <char> store;

        for(char c : s){
            if(c >='a' && c <= 'z' || (c>='A' && c <= 'Z')){
                store.push(c);
            }
            else{
                continue;
            }
        }

        for(int i = 0 ; i < s.size();i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >='A' && s[i] <= 'Z')){
                result+= store.top();
                store.pop();
            }
            else{
                result+= s[i];
            }

        }

        return result;


        
    }
};