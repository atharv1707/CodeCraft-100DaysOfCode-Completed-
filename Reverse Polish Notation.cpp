class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack <int> store;

        for(auto& token : tokens){
             if (token == "+" || token == "-" || token == "*" || token == "/") {

            //just read it once about RPN , it's very simple to understand. Basic stack push and pop.
            //use stoi when needed.
            
            

            int operand2 = store.top();
            store.pop();
            int operand1 = store.top();
            store.pop();

            

            int result;
            if (token == "+")
                result = operand1 + operand2;
            else if (token == "-")
                result = operand1 - operand2;
            else if (token == "*")
                result = operand1 * operand2;
            else if (token == "/")
                result = operand1 / operand2;

            store.push(result);    
        }
        else{
            store.push(stoi(token));
        }
        }

       return store.top();
        
    }
};