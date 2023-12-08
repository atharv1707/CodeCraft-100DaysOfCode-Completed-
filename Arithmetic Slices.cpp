//O(N^2) 

class Solution {
public:
    bool checkSubarr(int i, int j, vector<int>& nums){
        for(int k = i + 2; k <= j; k++) {
            int prevDiff = nums[k-1] - nums[k-2];
            int currDiff = nums[k] - nums[k-1];

            if (prevDiff != currDiff) {
                return false;
            }
        }
        
        
        

        return true;
    }

    int numberOfArithmeticSlices(vector<int>& nums) {

        if(nums.size() < 3){
            return 0;
        }

        int i = 0 ;
        int n = nums.size();
        int count = 0 ;
        
        while(i < n){
            for(int j = i+2 ; j < n ; j++){
                if(checkSubarr(i,j,nums)){
                    count++;
                }
            }

            i++;

        }

        return count;
        
    }
};


