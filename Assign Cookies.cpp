class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        unordered_set<int> content_children;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0 ;

        for(int i = 0 ; i < s.size() ; i++){
            int cookie = s[i];

            for(int j = 0 ; j < g.size() ; j++){
                int greed_factor = g[j];
                if(cookie >= greed_factor ){
                    if(content_children.find(j) == content_children.end()){

                        count++;
                        content_children.insert(j);
                        break;

                    }
                    
                }
                else{
                        break;
                    }
            }
        }

        return count;




        
    }
};