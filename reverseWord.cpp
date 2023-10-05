class Solution {
public:
    string reverseWords(string s) {

        //using stack
        stack<string> wordStack;
        string word;

        //start making word
        for(char c : s){
            if(c == ' '){
                if(!word.empty()){
                    //check if string is not empty
                    wordStack.push(word);
                    word = ""; //reset the word after inserting it in the stack
                }
                
            }else{
                word += c;
            }
        }

        //taking care of the case for the last word when there is not space after that

        if(!word.empty()){
            wordStack.push(word);
            word = "";
        }

        //start making the reversed string

        string result = "";

        while(!wordStack.empty()){
            //inserting the top word of the stack ;
            result += wordStack.top();
            wordStack.pop(); //deleting the word added to the latest to make sure no word is repeated and we get to next word

            //adding spaces after each word
            if(!wordStack.empty()){
                result += " ";
            }

        }

        return result;







        

        
    }
};