class Solution {
public:
    int findMaxLen(vector<int>& nums , int idx){
        int currLen = 0;
        int MaxLen = 0 ; 

        for(int i = 0 ; i < nums.size() ; i ++){
            if(i == idx){
                continue ;
            }

            if(nums[i] == 1){
                currLen++;
                MaxLen = max(MaxLen, currLen);
            }
            else{
                currLen = 0 ; 
            }

        }

          return MaxLen;
    }
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int countZeroes = 0 ; 
        int result = 0; 
        for(int i = 0 ; i < n; i++ ){
            
            if(nums[i] == 0){
                countZeroes ++;
                result = max(result, findMaxLen(nums, i));
            }
        }

        if(countZeroes == 0){
            return n-1;
        }

        return result;
        
    }
};


//approach  2 

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0 ; 
        int zer = 0 ; 

        int i = 0 ; 
        for(int j = 0 ; j < n;j++){
            if(nums[j] ==0){
                zer++;
            }

            while(zer > 1){
                if(nums[i] == 0){
                    zer--;
                }

                i++;
            }

            maxLen = max(maxLen, j-i);
        }
        
        return maxLen;
    }
};