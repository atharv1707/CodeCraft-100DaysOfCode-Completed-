class Solution {
public:
    string removeStars(string s) {

        stack<char> store;

        for(char c : s){
            if(c == '*'){
                store.pop();
            }
            else{
                store.push(c);
            }

        }

        string result = "";

        while(!store.empty()){
            result.push_back(store.top());
            store.pop();

        }
        reverse(result.begin(), result.end());

        return result;
        
    }
};

//apporach 2 :  TLE 

class Solution {
public:
    string removeStars(string s) {

        for(int i = 0 ; i< s.length() ; i++){
            if(s[i] == '*'){
                if(i > 0 && s[i-1] != '*'){
                    s.erase(i-1,2);
                    i = i-2;
                }
                else{
                    s.erase(i,1);
                }
            }
        }

        return s;
        
    }
};