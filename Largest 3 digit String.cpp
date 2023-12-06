class Solution {
public:
    string largestGoodInteger(string num) {

        string result = "";

        set<string> store{"111", "222", "333", "444", "555","666", "777","888", "999", "000"};

        for(int i = 0 ; i < num.size()-2; i ++){
            string sub = num.substr(i, 3);

            if(store.find(sub) != store.end()){
                if(result < sub){
                    result = sub;
                    
                }


            }

           

        }

         return result;
        
    }
};