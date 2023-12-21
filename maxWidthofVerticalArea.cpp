class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<long long> freqArray(1e9 + 1, 0);
        long long curr = 0;  
        long long ans = 0;

        for (auto &pair : points) {
            freqArray[pair[0]]++;
        }

        for (int i = 0; i < freqArray.size(); i++) {
            if (freqArray[i] != 0) {
                long long start = i;
                long long end = i;

                while (end < freqArray.size() && freqArray[end] != 0) {
                    end++;
                }

                curr = end - start + 1;  
                ans = max(ans, curr);  
            }
        }

        return ans;
    }
};

//approach 2 

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        vector<long long> store;

        for(auto &pair : points){
            store.push_back(pair[0]);
        }

        sort(store.begin(), store.end());
        long long maxGap = 0;
        long long curr = 0 ;

        for(int i = 1 ; i < store.size() ; i++){

            curr = store[i] - store[i-1];
            maxGap = std::max(maxGap, curr);
        }

        return maxGap;

        
    }
};