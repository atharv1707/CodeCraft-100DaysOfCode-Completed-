#include <unordered_map>
#include <vector>

class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, int> track;

        for (char c : s) {
            track[c]++;
        }

        std::vector<int> freqSorted;

        for (const auto &pair : track) {
            if (pair.second % 2 == 0) {
                freqSorted.push_back(pair.second);
            } else {
                freqSorted.push_back(pair.second - 1); // Include all even frequencies
            }
        }

        int length = 0;
        for (int i : freqSorted) {
            length += i;
        }

        // If there is any character with an odd frequency, add 1 to the length
        if (s.size() > length) {
            length += 1;
        }

        return length;
    }
};
