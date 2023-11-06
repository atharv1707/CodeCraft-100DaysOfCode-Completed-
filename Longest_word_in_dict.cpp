class Solution {
public:
    bool static customSort(string S1, string S2){
        //we are going for longest word , thus descending order
        if(S1.size() > S2.size()){
            return true;
        }
        else if( S1.size() < S2.size()){
            return false;
        }
        //in case both strings are same in length
        else{
            return S1 < S2; //it checks lexicographically then
        }
    }
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), customSort);

        for(string word :d ){
            //checking for subsequence
            int i = 0 ;
            int j = 0 ; 
            while(i < s.length() && j < word.length()){
                if(s[i] == word[j]){
                    j++;
                }
                i++;
            }

            if(j == word.length()){
                //that means we got our word. it has all characters and is lexicographically correct too.
                return word;
            }
        }

        return "";

        
    }
};