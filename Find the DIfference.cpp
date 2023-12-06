class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> freq;

        for(char c : s ){
            freq[c]++;
        }

        for(char c : t){
            if(freq.find(c) == freq.end() || freq[c] == 0){
                return c;
            } else{
                freq[c]--;
            }

        }

        

        

        return NULL;

        
    }
};