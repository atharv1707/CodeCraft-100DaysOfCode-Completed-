
//solution 0 , it passes 39/42 testcases. Edge cases...*sighs, it doesn't do the one-to-one mapping effectively though
vector<string> splitString(const string& a) {
    vector<string> words;
    istringstream iss(a);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> storeString = splitString(s);
        unordered_map<char, string> _map;

        if (pattern.length() != storeString.size())
            return false;

        for (int i = 0; i < pattern.length(); i++) {
            if (_map.find(pattern[i]) == _map.end()) {
                _map.insert({pattern[i], storeString[i]});
            } else {
                if (_map[pattern[i]] != storeString[i])
                    return false;
            }
        }

        return true;
    }
};




///solution 2 this one passes all testcases



vector<string> splitString(string a) {
    vector<string> words;
    istringstream iss(a);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> storeString = splitString(s);
        unordered_map<char, string> patToWord;
        unordered_map<string, char> wordToPat;
        //two maps for ensuring one-to-one mapping

        if (pattern.length() != storeString.size()) {
            return false;
        }

        for (int i = 0; i < pattern.length(); i++) {
            char currentPatternChar = pattern[i];
            string currentWord = storeString[i];

            // Check if the pattern character is already mapped to a word
            if (patToWord.find(currentPatternChar) != patToWord.end()) {
                if (patToWord[currentPatternChar] != currentWord) //this line of code is when the mapping of the character is already done 
                 {
                    return false;  // Pattern character is mapped to a different word
                }
            } else {
                patToWord[currentPatternChar] = currentWord;  // Create a new mapping
            }

            // Check if the word is already mapped to a pattern character
            if (wordToPat.find(currentWord) != wordToPat.end()) {
                if (wordToPat[currentWord] != currentPatternChar) //this line of code is when the mapping of the word is already done  
                {
                    return false;  // Word is mapped to a different pattern character
                }
            } else {
                wordToPat[currentWord] = currentPatternChar;  // Create a new mapping
            }
        }

        return true;
    }
};

