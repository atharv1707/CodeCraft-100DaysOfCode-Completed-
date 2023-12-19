// approach O(N^2) 



class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        int n = arr.size();
        for(int i = 0 ; i < n ;i++ ){
            
            int max = -1;

            for(int j = i+1; j < n ; j++){
                if(arr[j] > max){
                    max = arr[j];
                }
            }
            arr[i] = max;
        }
       return arr; 
        
    }
};

// approach 2 

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        int current_max = -1;

        int n = arr.size();
        
        for(int i = n-1; i>=0; i--) {  

            if(arr[i] > current_max) {
                swap(arr[i], current_max); 
            }
            else {
                arr[i] = current_max;
            }
        }

        return arr;
        
    }
};


//approach 3 


