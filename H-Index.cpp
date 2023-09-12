class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();
        int start = 0 ;
        int end = n -1 ;

        // sort(citations.begin(), citations.end());


        while(start<=end){

            int mid = start + (end-start)/2;
            if(citations[mid] == n-mid){
                return n-mid;
            }
            else if(citations[mid] < n-mid){   
                start = mid + 1;
            }
            else if(citations[mid] > n-mid){
                end = mid-1;
            }

        }

        return n-start;

        
        
    }
};