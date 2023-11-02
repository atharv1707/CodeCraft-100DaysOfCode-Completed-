

class Solution {
public:
    string removeOccurrences(string s, string part) {
        for (int i = 0; i <= s.size() - part.size();) {
            if(s.size() < part.size()){
                return s;
            }
            //we take substring from current index and of length part.size()
            if (part == s.substr(i, part.size())) {
                //if matches, we erase the damn string
                s.erase(i, part.size());
                //but the problem is - we need to check that we are not missing any potential match after the erase function, as per dry run, if we shift it back by part.size()
                i -=part.size();
                if(i <0){
                    i = 0 ;
                }
            } else {
                i++;
            }
        }

        return s;
    }
};
