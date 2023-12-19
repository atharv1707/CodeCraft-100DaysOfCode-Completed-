class Solution {
public:
    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> result;

        for(int i = 1 ; i < n-k+1 ; i++){
            for(int j = i+1 ; j<= n; j++){

                vector<int> combi;
                combi.push_back(i);

                for(int m = j; m <= n && combi.size() < k;m++){
                    combi.push_back(m);
                    
                }

                if(combi.size() == k){
                    result.push_back(combi);
                }
            }

        }

        return result;
        
    }
};


//approach 2 

class Solution {
public:
    void backtrack(vector<vector<int>>& result, vector<int>& current_combination, int start, int n, int k) {

        //base case 
        if(current_combination.size() == k){
            result.push_back(current_combination);
            return;
        }


        for(int i = start ; i <= n ; i++){
            current_combination.push_back(i);
            backtrack(result, current_combination, i + 1, n, k);
            current_combination.pop_back();
        }

    }


    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current_combination ;

        backtrack(result, current_combination, 1, n, k);
        return result;
        
    }
};
