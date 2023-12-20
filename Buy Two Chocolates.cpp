class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

        int original_money =  money;
        int remaining_money = money;

        sort(prices.begin(), prices.end());

        int chocolate1 = prices[0];
        int chocolate2 = prices[1];

        remaining_money -= (chocolate1+ chocolate2);


        if(remaining_money < 0){
            return original_money;
        }  

        return remaining_money;
        
    }
};


// approach 2 


#include <vector>

class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) {

        // Implementing counting sort
        vector<int> freqArr(101, 0);
        int n = prices.size();
        for (int i : prices) {
            freqArr[i]++;
        }

        int index = 0;

        for (int i = 0; i < 101; i++) {  // Fix: Change to i < 101
            while (freqArr[i] > 0) {
                prices[index++] = i;
                freqArr[i]--;
            }
        }

        int orig_money = money;
        int rem_money = money;

        int money_spent = prices[0] + prices[1];  // Fix: Use prices array

        rem_money -= money_spent;

        if (rem_money < 0) {
            return orig_money;
        }

        return rem_money;
    }
};

//approach 3 -> use two pass or one pass -> that is keep track of minumium and second minimum -> or we can assume first two as min and sec min and then keep moving forward to change them as needed. 
