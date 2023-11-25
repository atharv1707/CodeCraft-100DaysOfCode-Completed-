class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0 ;
        int minLen = numeric_limits<int> max(); 
        int i = 0 ; 
        for(int j = 0 ; j < nums.size();j++){
         sum += nums[j];
         while(sum >= target){
             minLen = min(minLen, j-i+1);

             sum -= nums[i];
             i++;
         }
        }
        
        return (minLen == numeric_limits<int> max()) ? 0 : minLen;

       
        
    }
};