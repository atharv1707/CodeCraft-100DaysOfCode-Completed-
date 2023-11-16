#include <string>

class Solution {
public:
    std::string truncateSentence(std::string s, int k) {
        std::string result = "";
        int spaceCount = 0;
        int i = 0;

        while (spaceCount < k && i < s.length()) {
            if (s[i] == ' ') {
                spaceCount++;
            }
            result += s[i];
            i++;
        }

        // Remove the last character if it is a space
        if (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
