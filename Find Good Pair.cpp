//brute force


class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        for(int i = 0 ; i < nums.size(); i++){
            for(int j =  ; j < nums.size();j++){
                if(nums[i] == nums[j]){
                    result++;
                }
            }
        }

        return result;
        
        
    }
};


//optimised approach
class Solution {
public:

    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int, int> freq;
        int result = 0 ;
        vector<int> store;
        for(int i : nums){
            freq[i]++;
        }

        for(const auto& i : freq){
            if(i.second > 1){
                result += ((i.second)*(i.second-1))/2;
                
            }
        }


        return result;

        
    }
};