class Solution {
    private:
    bool checkEqual(int a[26], int b[26]){
        for(int i = 0 ; i< 26; i++){
            if(a[i] != b[i]){
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {

        //going through first string and mapping each character
        int count[26] = {0};

        for(int i = 0 ; i<s1.length();i++){
            int index = s1[i] - 'a';
            count[index]++;
        }
        
        //traversing s2 string with window of size s1.length

        int i = 0;
        int winSize = s1.length();
        //we make another count array and we will compare them.
        int count1[26] = {0};


        while(i<winSize && i<s2.length()){
            int index = s2[i] - 'a';
            count1[index]++;
            i++; //we proceed in traversal
        }

        if(checkEqual(count, count1)){
            return true;
        }

        //if match not found in this iteration, go next.
        while(i<s2.length()){


            char newChar = s2[i];
            int index = newChar - 'a';
            count1[index]++;

            int oldChar = s2[i-winSize];
            index = oldChar - 'a';
            count1[index]--;
            i++;

            if(checkEqual(count, count1)){
                return 1;
            }
        }

        return false;


    }
};