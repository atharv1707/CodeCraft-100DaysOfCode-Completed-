class Solution {
public:
    string smallestSubsequence(string s) {

        int len = s.length();
        string result = "";

        ///boolean vector
        vector<bool> charUsed(26,false);

        //storing the last index
        vector<int> lastIndex(26,-1);

        for(int i = 0 ; i < len ; i++){
            char c = s[i];
            lastIndex[c - 'a'] = i;
        }

        for(int i = 0 ; i < len ; i++){

            char ch = s[i];

            int idx = ch-'a';

            if(charUsed[idx] == true){
                continue;
            }

            while(result.length() > 0 && result.back() > ch && lastIndex[result.back() - 'a'] > i){
                charUsed[result.back() -'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            charUsed[idx] = true;



        }


        return result;
        
    }
};