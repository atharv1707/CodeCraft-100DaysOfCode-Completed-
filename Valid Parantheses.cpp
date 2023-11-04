class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;
        
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                brackets.push(c);
            } else if (!brackets.empty() && ((c == ')' && brackets.top() == '(') || 
                                            (c == ']' && brackets.top() == '[') || 
                                            (c == '}' && brackets.top() == '{'))) {
                brackets.pop();
            } else {
                return false;
            }
        }
        
        return brackets.empty();
    }
};



//approach 2


class Solution {
public:
    bool check_substr(string sub) {
        return (sub == "()" || sub == "[]" || sub == "{}");
    }

    bool isValid(string s) {
        for (int i = 0; i < s.size(); ) {
            if (i + 1 < s.size() && check_substr(s.substr(i, 2))) {
                s.erase(i, 2);
                i = 0; 
            } else {
                i++;
            }
        }
        return s.empty(); 
    }
};
