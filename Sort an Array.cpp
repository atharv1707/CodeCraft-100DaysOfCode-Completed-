//approach 1 : Brute Force

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted;

        while(!nums.empty()){
            int n = nums.size();
            int min_element = INT_MAX;
            int min_index = -1;

            for(int i = 0 ; i < n ; i ++){
                if(nums[i] < min_element){
                    min_element = nums[i];
                    min_index = i;
                }
            }

            sorted.push_back(nums[min_index]);
            nums.erase(nums.begin()+min_index);
        }

        return sorted;
        
    }
};

//Approach  2  : Counting Sort 

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        //Counting Sort
        unordered_map<int, int> store;

        for(int &num : nums){
            store[num]++;
        }

        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement  = *max_element(nums.begin(), nums.end());

        int index_to_replace = 0;

        for(int i  = 0 ; i <= maxElement ; i++){
            while(store[i] > 0){
                nums[index_to_replace] = i;
                index_to_replace++;
                store[i]--;

            }

        }

        return nums;


        
    }
};

