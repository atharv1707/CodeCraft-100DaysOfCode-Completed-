class Solution {
public:
    string customSortString(string order, string s) {
        string result = "";
        //to store the occurences of the each character, we need to store it in a map.
        unordered_map<char, int> countChar;


        for(char c : s){
            countChar[c]++;
        }

        for(char c : order){
            if(countChar.find(c) != countChar.end()){
                result+= string(countChar[c], c);
                countChar.erase(c);
            }
        }

        //adding the remaining chars whose order we don't know
        for(auto entry : countChar){
            result+= string(entry.second, entry.first);  
        }

        return result;


    }
};