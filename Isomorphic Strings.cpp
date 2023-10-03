class Solution {
public:
    bool isIsomorphic(string s, string t) {

        vector<char> mapS(128,0);
        vector<char> mapT(128,0);

        int len = s.size();
        for(int i = 0 ; i< len ; i++){
            if(mapS[s[i]] != mapT[t[i]]){
                return false;
            }
            mapS[s[i]] = i+1; //if not mapped before, assign it i+1
            mapT[t[i]] = i+1; //mapping it same, so if we encounter non-unique mapping of letters, we return false. 

        }
        return true;
    }
};