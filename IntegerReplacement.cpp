#include <limits.h>

class Solution {
public:
    int integerReplacement(int n) {
        int count = 0;

        while (n != 1) {
            if ((n & 1) == 0) {
                // even condition
                n >>= 1;
                count++;
            } else if (n == 3 || ((n >> 1) & 1) == 0) {
                //case n ==3 is special. It's better to go for 10 than 100
                // for odd numbers, decrement if n is 3 or (n+1) has fewer set bits
                if (n == INT_MAX) {
                    n /= 2;  // to handle potential overflow
                } else {
                    n--;
                }
                count++;
            } else {
                // 
                if (n == INT_MAX) {
                    // 
                    n /= 2;
                } else {
                    n++;
                }
                count++;
            }
        }

        return count;
    }
};
