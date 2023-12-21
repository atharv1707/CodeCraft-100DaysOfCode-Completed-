class Solution {
public:

    void backtrack(const vector<int>& nums, int start, vector<int>& curr_subset, vector<vector<int>>& result) {

        result.push_back(curr_subset);

        for(int i = start ; i < nums.size() ; i++){
            curr_subset.push_back(nums[i]);
            backtrack(nums, i+1, curr_subset, result);
            curr_subset.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> curr_subset;


        backtrack(nums, 0, curr_subset, result);

        return result;



        
        
    }
};