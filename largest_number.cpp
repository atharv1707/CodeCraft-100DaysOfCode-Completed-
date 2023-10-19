#include <algorithm>
#include <vector>
#include <string>

class Solution {
public:
    static int compare(string a , string b){
        if(a + b > b+ a){
            return true;
        }

        // else if( a+ b == b+a){
        //     return 0;
        // }

        else{
            return false;
        }
    }

    string largestNumber(vector<int>& nums) {
        vector<string> numStrings;

        // Convert the whole vector from numbers to strings
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }

        // Custom sort using the static member function as a comparator
        //if a+b > b+a is true, a comes first and if not then b comes first in sorting. Simple.
        sort(numStrings.begin(), numStrings.end(), compare);

        // If the largest number is "0"
        if (numStrings[0] == "0") {
            return "0";
        }

        // Concatenate the sorted strings
        string result;
        for (string i : numStrings) {
            result += i;
        }

        return result;
    }
};
