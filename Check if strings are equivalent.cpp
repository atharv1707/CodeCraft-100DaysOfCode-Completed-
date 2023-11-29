
//approach 1 
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string result1 = "";
        string result2 = "";

        for(int i = 0 ; i < word1.size();i++){
            result1+=word1[i];
        }

        
        for(int i = 0 ; i < word2.size();i++){
            result2+=word2[i];
        }
        

        if(result1 == result2){
            return true;
        }
        else{
            return false;
        }
    }
};


//approach 2 

class Solution {
public:
    vector<int> crazyfunction(vector<string>& WORDS) {
        int count = 1;

        vector<int> charArray(26, 0);
        for (const string& word : WORDS) {
            for (char c : word) {
                charArray[c - 'a'] = count;
                count++;
            }
        }

        return charArray;
    }

    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return crazyfunction(word1) == crazyfunction(word2);
    }
};

