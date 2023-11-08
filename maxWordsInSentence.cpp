//approach 1

class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int maxWords = 0 ; 

        for(const string& sent : s){
            int currWords = 0 ; 

            int i = 0 ; 
            for(char c : sent){
                if(c == ' '){
                    currWords++;
                }
                i++;
            }
            currWords ++; //the last word 

            maxWords = max(maxWords, currWords);

        }

        return maxWords;

        

        
    }
};

//approach 2 

class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int maxWords = 0 ; 

        for(const string& sent : s){
            int currWords = 0 ; 
            int spaces = 0 ; 

            for(char c : sent){
                if(c == ' '){
                    spaces++;
                }
            }

            currWords = spaces +1 ;
            maxWords = max(maxWords, currWords);
        }

        return maxWords;


        

        
    }
};