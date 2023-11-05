
//both the approaches mean the same thing
//approach 1

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {        
    unordered_map<char, int> alienOrder;

    // Create a mapping of characters to their order indices
    for (int i = 0; i < order.size(); i++) {
        alienOrder[order[i]] = i;
    }

    for(int i = 1 ; i < words.size();i++){
        string prevWord = words[i-1];
        string currWord = words[i];

        int minLength = min(prevWord.size(), currWord.size());

        for(int j = 0 ; j < minLength ; j++){
            if(alienOrder[prevWord[j]] < alienOrder[currWord[j]]){
                break; //valid order
            } 
            else if(alienOrder[prevWord[j]] > alienOrder[currWord[j]]){
                return false;
            }

        }

        //it might be possible that prevWord was greater in length and it was greater in lexicographical order, thus it should be after the currWord.
        if(prevWord.length() > currWord.length() && prevWord.compare(0, currWord.length(), currWord) == 0){
            //If this comparison returns 0, it means that the portion of previousWord starting at the beginning and having the same length as currentWord is equal to currentWord. In other words, previousWord starts with currentWord.

            return false;

        }


    }

    return true;
        
    }
};


//approach 2 
//the idea here is to check different lengths of the string and see if first character is smaller rank or not than the next word.

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> charRank;
        for (int i = 0; i < order.size(); i++) {
            charRank[order[i]] = i;
        }

        for (int i = 1; i < words.size(); i++) {
            if (!isOrdered(words[i - 1], words[i], charRank)) {
                return false;
            }
        }

        return true;
    }

private:
    bool isOrdered(const string& word1, const string& word2, unordered_map<char, int>& charRank) {
        int len1 = word1.size();
        int len2 = word2.size();

        for (int i = 0; i < min(len1, len2); i++) {
            if (charRank[word1[i]] < charRank[word2[i]]) {
                return true;
            } else if (charRank[word1[i]] > charRank[word2[i]]) {
                return false;
            }
        }
        
        return len1 <= len2;
    }
};
