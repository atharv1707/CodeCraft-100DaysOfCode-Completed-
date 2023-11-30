class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i = 0 ; 
        int j = nums.size()-1;
        sort(nums.begin(), nums.end());
        int sum = 0;
        int maxSum = 0;

        while(i < j){
            sum = nums[i] + nums[j];
            maxSum = max(maxSum, sum);
            i++;
            j--; 
        }

        return maxSum;


        
    }
};