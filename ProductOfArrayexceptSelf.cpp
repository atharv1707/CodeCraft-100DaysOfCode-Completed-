#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(n, 0);  // Initialize ans with size n and all elements as 0.
        int zeroCount = 0;
        int product = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                zeroCount++;
                if (zeroCount > 1) {
                    // Multiple zeros, all products would be zero
                    return ans;
                }
                continue;  // Skip the zero, don't include it in the product calculation
            }
            product *= nums[i];
        }

        if (zeroCount == 1) {
            // There's only one zero, so the product is zero for all elements except that zero
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    ans[i] = product;
                    break;
                }
            }
        } else {
            // There are no zeros, so calculate the product normally
            for (int i = 0; i < n; i++) {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};
