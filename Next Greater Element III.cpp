class Solution {
public:
    int nextGreaterElement(int n) {

        string num = to_string(n);

        int idx = num.length()-1;

        while(idx>0 && num[idx] <= num[idx-1]){
            idx--;
        }

        if(idx==0){
            return -1; //all fine
        }

        int smallestGreaterthanIDX = idx;
        for(int i = idx+1 ; i < num.length();i++){
            if(num[i] > num[idx-1] && num[i] <= num[smallestGreaterthanIDX]){
                smallestGreaterthanIDX = i;

            }
        }

        swap(num[idx-1], num[smallestGreaterthanIDX]);

        reverse(num.begin()+idx, num.end());

        long long result = stoll(num);

        return (result>INT_MAX) ? -1 : static_cast<int>(result);
        
    }
};