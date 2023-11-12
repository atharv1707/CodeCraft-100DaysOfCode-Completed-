class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
        return "0";
    }

        string result = "";
        bool isNegative = false;
         if (num < 0) {
            isNegative = true;
            num = -num;
        }

        while(num>0){
            char digit = '0' + num%7;
            result = digit + result;
            num /=7;
        }
        if(isNegative){
            result = "-" + result;
        }

        return result;

        
    }
};