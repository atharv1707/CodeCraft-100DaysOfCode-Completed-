class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int i = 0 ; //this one goes to catching the j
        int j = 0 ; //this traverses to each place where we don't have a zero

        // we have to move the non zeroes at initial places as much as possible

        while( j < nums.size()){

            if(nums[j] != 0){
                swap(nums[j], nums[i]);
                i++; //move on to next index to have another non zero element 

            }

            j++; //keep traversing each element
            

        }
        
    }
};
