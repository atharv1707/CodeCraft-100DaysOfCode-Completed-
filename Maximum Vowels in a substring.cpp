class Solution {
public:
    int maxVowels(string s, int k) {

        int i = 0 ; 
        int j = 0 ; 
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int currCount = 0 ;
        int maxCount = 0 ; 
        

        for(j; j< k; j++){
            if(vowels.find(s[j]) != vowels.end()){
                currCount++;
            }
        }

        maxCount = max(maxCount, currCount);

        for(j ; j < s.size();j++){

            if(vowels.find(s[j]) != vowels.end()){
                currCount++;
            }

            if(vowels.find(s[i]) != vowels.end()){
                currCount--;
            }
            i++;

            maxCount = max(currCount, maxCount);


            

        }

        return maxCount;


        
    }
};