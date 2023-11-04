class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> open;
        set<int> remove;

        for(int i = 0; i < s.size() ; i ++){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == ')'){
                if(!open.empty()){
                    open.pop();
                }
                else{
                    remove.insert(i);
                }
            }
            else if(!(s[i]>='a' && s[i] <= 'z')){
                remove.insert(i);
            }
        }

        //checking for the unpaired open parantheses
        while(!open.empty()){
            remove.insert(open.top());
            open.pop();
        }

        //building the string
        string result = "";
        for(int i = 0 ; i < s.size(); i++){
            if(remove.find(i) == remove.end()){
                result += s[i];
            }
        }

        return result;
        
    }
};