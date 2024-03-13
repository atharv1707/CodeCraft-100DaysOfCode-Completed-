class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        sort(arr, arr + N);
        string shortest =  arr[0];
        string longest = arr[N-1];
        
        string result = "";
        
        for(int i = 0 ; i < shortest.size();i++){
            
            if(shortest[i] == longest[i]){
                result+= shortest[i];
            }
            
            else{
                break;
            }
        }
        
        if(result == ""){
            return "-1";
        }
        
        return result;
        
        
    }
};
