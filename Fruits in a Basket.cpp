//Brute Force 
class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int i = 0 ;
        int n = fruits.size();
        int maxLen = 0 ;

        while(i < n){
            int j = i ;
            int currLen = 0 ;
            unorderd_set<int> distinct;
            while(j < n && distinct.size() <= 2){
                distinct.insert(fruits[j]);

                if(distinct.size() <= 2){
                    //this is a valid subarray
                    currLen = j-i+1;
                    maxLen
                    
                }


            }
        }
        
    }
};

//Optimised

#include <vector>
#include <unordered_map>

class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        std::unordered_map<int, int> fruitLastIndex; // Map to store the last index of each fruit

        int i = 0, j = 0;

        while (j < n) {
            fruitLastIndex[fruits[j]] = j;

            if (fruitLastIndex.size() > 2) {
                int minLastIndex = n;
                for (const auto& entry : fruitLastIndex) {
                    minLastIndex = min(minLastIndex, entry.second);
                }

                i = minLastIndex + 1;
                fruitLastIndex.erase(fruits[minLastIndex]);
            }

            maxLen = max(maxLen, j - i + 1);
            ++j;
        }

        return maxLen;
    }
};
