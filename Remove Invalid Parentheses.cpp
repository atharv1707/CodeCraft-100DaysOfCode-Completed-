#include <vector>
#include <unordered_map>
#include <stack>
#include <string>

class Solution {
public:
    std::vector<std::string> res;
    std::unordered_map<std::string, int> mp;

    int getMinInvalid(const std::string& s) {
        std::stack<char> stck;
        for (char c : s) {
            if (c == '(') {
                stck.push('(');
            } else if (c == ')') {
                if (!stck.empty() && stck.top() == '(') {
                    stck.pop();
                } else {
                    stck.push(')');
                }
            }
        }
        return stck.size();
    }

    void generateValidExpressions(const std::string& s, int minInvalid) {
        if (mp[s] != 0) {
            return;
        } else {
            mp[s]++;
        }

        // Base case
        if (minInvalid < 0) {
            return;
        }

        if (minInvalid == 0 && getMinInvalid(s) == 0) {
            res.push_back(s);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            string left = s.substr(0, i);
            string right = s.substr(i + 1);
            generateValidExpressions(left + right, minInvalid - 1);
        }
    }

    std::vector<std::string> removeInvalidParentheses(const std::string& s) {
        int minInvalid = getMinInvalid(s);
        generateValidExpressions(s, minInvalid);
        return res;
    }
};
