class Solution {
public:

    bool possible(vector<int>weights,int n, int days,int  mid){

        int weightSum = 0 ; 
        int Days = 1;

        for(int i = 0 ; i <n; i++){
            if(weightSum + weights[i] <= mid){
                weightSum+= weights[i];
            }
            else{
                Days++;
                if(Days > days || weights[i] > mid){
                    return false;
                }
                weightSum = weights[i];
            }
            
        }

        return true;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        int start = 0 ;
        int sum =  0 ; 
        for(int i = 0 ; i <n ; i++){

            sum += weights[i];
        } 

        int end = sum;
        int ans = -1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(possible(weights, n,days,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid +1;

            }
        }
        return ans;
     
    }
};