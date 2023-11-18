class Solution {
public:
 
    string replaceWords(vector<string>& dict, string s) {
        sort(dict.begin(), dict.end());
        string result = "";
        vector<string> store;
        string temp = "";
        int last = 0 ;
        int i = 0 ; 

        for(int j = 0 ; j < s.length(); j++){
            
            if(s[j] == ' '){
                temp = s.substr(i,j-i);
                store.push_back(temp);
                temp = "";
                i = j+1;
            }
        }

        temp = s.substr(i,s.length()-1);
        store.push_back(temp);
        temp = "";

        for(string c: store){
            bool replaced = false; //if the dict is not replacing the current word,in that case, we need to use this to print the word as it is.
            for(string l : dict){
                if(c.find(l) == 0){
                    result+= l + " ";
                    replaced = true;
                    break;
                }
                
            }

            if(!replaced){
                result+= c + " ";
            }

            //to remove the trailling spaces.
            
        }
        int k = 0 ;
    
        result.erase(result.find_last_not_of(" \t") + 1);

        return result;



        
        
    }
};