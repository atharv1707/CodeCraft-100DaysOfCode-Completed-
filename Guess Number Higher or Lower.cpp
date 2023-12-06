/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;

        while(left<=right){
            int our_guess = left + (right-left)/2;

            int decision = guess(our_guess);
            if(decision == 0){
                return our_guess;
            }
            else if(decision == -1){
                right = our_guess-1;
            }
            else{
                left = our_guess + 1;
            }
        }

        return -1;
        
    }
};