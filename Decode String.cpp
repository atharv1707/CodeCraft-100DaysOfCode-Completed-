class Solution {
public:
    string decodeString(string s) {

        stack<char> charStack;

        for(char c : s){
            if(c != ']'){
                charStack.push(c);
            
            }
            else{
                string temp = "";
                while(!charStack.empty() && charStack.top() != '['){
                    temp = charStack.top() + temp;
                    charStack.pop();
                }
                charStack.pop();
                
                string CountStr = "";
                while(!charStack.empty() && isdigit(charStack.top())){
                    CountStr = charStack.top() + CountStr;
                    charStack.pop();
                }

                int count = stoi(CountStr);

                for(int i = 0 ; i < count ;i++){
                    for(char c : temp){
                        charStack.push(c);
                    }
                }
            }
        }

        //decoding the final stack into the string

        string result = "";
        while(!charStack.empty()){
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
        
    }
};