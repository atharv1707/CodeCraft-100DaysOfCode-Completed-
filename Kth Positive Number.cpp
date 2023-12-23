
class Solution {
public:
    int findKthPositive(std::vector<int>& arr, int k) {
        int i = 1;
        bool status = true;

        while(status) {
            if (std::find(arr.begin(), arr.end(), i) == arr.end()) {
                k--;
            }

            if (k <= 0) {
                status = false;
                break;
            }

            i++;
        }

        return i  ;
    }
};


//better solution 

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int current_number  = 1;
        int missing_numbers = 0 ; 
        int i = 0 ; 

        while(missing_numbers < k){
            if(i < arr.size() && arr[i] == current_number){
                i++;
            }
            else{
                missing_numbers++;

            }

            if(missing_numbers == k){
                return current_number;
            }

            current_number++;
        }

        return 0;

        
    }
};