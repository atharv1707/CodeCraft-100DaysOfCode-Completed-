class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0;
        int end = 0  ; 
        int n = s.size();
        unordered_map<char, int> track;
        int best_start = 0 ; 
        int counter = t.length();
        int windowSize = INT_MAX;

        for(char c : t){
            track[c]++;
        }

        while(end < n){
            
            if(track[s[end]] > 0){
                counter -- ; 
            }

            track[s[end]]--; //reduce the frquency of the element from map as well

            while(counter == 0){
                
                if (end - start + 1 < windowSize) {
                    windowSize = end - start+1;
                    best_start = start;
                }
                
                track[s[start]] ++;
           //now when we move, we will potentially bypass the required character, so we can just increase that char freq in our map and similarly the counter

                if(track[s[start]] > 0){
                    counter++;
                }
                start++;       
        }
        end++;
    }
        return (windowSize == INT_MAX) ? "" : s.substr(best_start, windowSize);
 
    }
};