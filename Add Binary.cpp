

class Solution {
public:
    string addBinary(string a, string b) {

        int carry = 0;
        
        int max_size =  max(a.size(), b.size());
        string res = "";

        
        for(int i = 0 ; i < max_size ; i++){

            int bit_a = (i < a.size()) ? a[a.size()-1-i]-'0' : 0;
            int bit_b = (i < b.size()) ? b[b.size()-1-i]-'0' : 0;

             int sum = (bit_a + bit_b + carry);
             res.insert(res.begin(), (sum % 2) + '0');
            
            carry = sum/2;          
        }

        if(carry>0){
            res.insert(res.begin(), carry + '0');
        }

        return res;


        
    }
};
