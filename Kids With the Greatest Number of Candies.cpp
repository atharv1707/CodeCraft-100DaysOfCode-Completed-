

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> status(candies.size(), false);

        int maxi = *std::max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); i++) {
            if (extraCandies + candies[i] >= maxi) {
                status[i] = true; 
            }
        }

        return status;
    }
};
