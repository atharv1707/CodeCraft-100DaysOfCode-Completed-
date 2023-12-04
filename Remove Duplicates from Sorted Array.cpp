class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0; //edge case
        }

        int i = 0 ; 
        int j = 0 ; 
        int count = 0 ;

        for(j=0; j < nums.size();){
            if(nums[i] == nums[j]){
                j++;
            }
            else if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
                count++;
                j++;
            }
        }


        return i+1;
        
    }
};
