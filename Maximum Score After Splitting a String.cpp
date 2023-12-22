class Solution {
public:
    int maxScore(string s) {

        int result = 0 ; 


        for(int i = 0 ; i < s.size()-1 ; i ++){
            string leftString  = s.substr(0,i+1);
            string rightString = s.substr(i+1);
            char zero = '0';
            char one = '1';

            int zeroOccur = count(leftString.begin(), leftString.end(), zero);
            int oneOccur = count(rightString.begin(), rightString.end(), one);

            int curr = zeroOccur + oneOccur;

            result = max(result, curr);

        }

        return result;
        
    }
};

class Solution {
public:
    int maxScore(string s) {

        int total_ones = count(s.begin(), s.end(), '1');

        int result = 0 ; 

        int ones = 0;
        int zeroes = 0;
        int n = s.length();

        //n-2 index -> till then only we can split it into two strings  
        for(int i = 0 ; i < n-1; i ++){
            if(s[i] == '1'){
                ones++;
            }
            else{
                zeroes++;
            }

            int right_ones = total_ones - ones;
            result = max(result, right_ones + zeroes);
        }

        return result;

        




        
    }
};