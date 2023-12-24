//my approach 

class Solution {
public:
    int minOperations(string s) {
        int count_0 = 0;
        int count_1 = 0;
        int n = s.length();       

        if (s[0] == '0') {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == s[i + 1]) {
                    count_0++;
                    s[i + 1] = '1';
                }
            }
        } else if (s[0] == '1') {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == s[i + 1]) {
                    count_1++;
                    s[i + 1] = '0';
                }
            }
        }

        int ans_1 = max(count_0, count_1);

        // Flipping the first character
        int flip_count_0 = 0;
        int flip_count_1 = 0;

        s[0] = (s[0] == '0') ? '1' : '0';

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                (s[i] == '0') ? flip_count_0++ : flip_count_1++;
                s[i + 1] = (s[i] == '0') ? '1' : '0';
            }
        }



        int ans_2 = max(flip_count_0, flip_count_1);

        return min(ans_1, ans_2);
    }
};


//correct approach 
//it's pretty simple once you notice a pattern

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        int start_0 = 0;
        int start_1 = 0;

        for(int i = 0 ; i < n ; i++){
            if(i%2 == 0){
                if(s[i] == '0'){
                    start_1++;
                }
                else{
                    start_0++;
                }

            }
            else{

                if(s[i] == '0'){
                    start_0++;
                }
                else{
                    start_1++;
                }

            }
        }

        return min(start_1, start_0);
        
    }
};

//third approach 

class Solution {
public:
    int minOperations(string s) {

        int count_1 = 0 ;
        int count_0 = 0 ;

        int n = s.length();

        for(int i = 0 ; i < n ; i++){
            int expected_bit = i%2;

            if(s[i] -'0' != expected_bit){
                count_0 ++;
            } 
            else{
                count_1++;
            }   
        }

        return min(count_0, count_1);
        
    }
};