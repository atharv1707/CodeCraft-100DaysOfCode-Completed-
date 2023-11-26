//TLE

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n = p.length();
        if(n > s.length()){
            return {};
        }
        sort(p.begin(), p.end());
        vector<int> Indexes;

        for(int i = 0 ; i < s.size()-p.size()+1;i++){
            string sub = s.substr(i,n);
            sort(sub.begin(), sub.end());
            if(sub == p ){
                Indexes.emplace_back(i);
            }


        }

        return Indexes;

        
    }
};

//A better Approach

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sfreq(26,0);
        vector<int> pfreq(26,0);

        int n = s.length();
        int m = p.length();
        if(n < m){
            return {};
        }
        vector<int> indexes;

        for(int i = 0 ; i < m;i++){
            sfreq[s[i]-'a']++;
            pfreq[p[i]-'a']++;
        }

        for(int i = m ; i < n ; i ++){
            if(sfreq == pfreq){
                indexes.emplace_back(i-m);
            }

            //slide the window to the right
            sfreq[s[i-m]-'a']--;
            sfreq[s[i]-'a']++;

        }

        //checking for the last substring
        if(pfreq == sfreq){
            indexes.emplace_back(n-m);
        }

        return indexes;
        
    }
};