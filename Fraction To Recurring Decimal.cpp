class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = (numerator < 0 || denominator < 0) ? "-" : "";
        if(numerator < 0 && denominator < 0){
            result = "";
        }
        if(numerator == 0){
            return "0";
        }
        long long num = abs(static_cast<long long>(numerator));
        long long den = abs(static_cast<long long>(denominator));
        long long q = num / den;
        long long rem = num % den;
        unordered_map<long long, int> rems;
        int repeatPos = -1; // here we will place the brackets
        result += to_string(q);
        int index = result.size(); // Keep track of the position in the result string

        if (rem == 0) {
            return result;
        } else {
            result += ".";
            while (rem != 0) {
                if (rems.find(rem) != rems.end()) {
                    repeatPos = rems[rem];
                    break;
                } else {
                    rems[rem] = index; // Store the position of the current remainder
                    num = rem * 10; // Multiply the remainder by 10 for the next iteration
                    q = num / den; // Calculate the next quotient
                    result += to_string(q); // Append the next digit to the result
                    rem = num % den; // Calculate the next remainder
                    index++;
                }
            }

            if (repeatPos != -1) {
                result.insert(repeatPos+1, "(");
                result += ")";
            }
        }

        return result;
    }
};
