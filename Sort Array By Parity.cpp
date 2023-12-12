class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        vector<int> result;

        for(int i : nums){
            if(i%2 == 0 ){
                result.insert(result.begin(), i);
            }
            else{
                result.push_back(i);
            }
        }


        return result;

        
    }
};

//approach 2 

#include <vector>

class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // Find the first odd element from the left
            while (left < right && nums[left] % 2 == 0) {
                left++;
            }

            // Find the first even element from the right
            while (left < right && nums[right] % 2 == 1) {
                right--;
            }

            // Swap the odd and even elements
            std::swap(nums[left], nums[right]);

            // Move the pointers
            left++;
            right--;
        }

        return nums;
    }
};
