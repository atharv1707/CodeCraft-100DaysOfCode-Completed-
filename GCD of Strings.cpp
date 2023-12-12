class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        int len1 = str1.length();
        int len2 = str2.length();

        int i = 0 ; 
        string ans = "";

        string smallerstring = (len1 > len2) ? str2 : str1;
        int lensmall = smallerstring.length();

        for(int j = i ; j < lensmall ; j++){

            string substring  = smallerstring.substr(i,j-i+1);

            string str1_repeat = "";
            string str2_repeat = "";

            //start buidling str1_repeat and str2_repeat
            
            int count1 = len1/(j-i+1);
            int count2 = len2/(j-i+1);

            for(int k = 0 ; k < count1; k++){
                str1_repeat += substring;
            }

            for(int k = 0 ; k < count2; k++){
                str2_repeat += substring;
            }


            if(str1_repeat == str1 && str2_repeat == str2){
                if(substring.length() > ans.length() ){
                    ans = substring;
                }
            }



        }

        return ans;


    }
};