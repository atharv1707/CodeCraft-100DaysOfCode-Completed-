class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        vector<std::pair<double, std::pair<int, int>>> fractions;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){
                double fraction = static_cast<double>(arr[i]) / static_cast<double>(arr[j]);
                fractions.push_back({fraction, {arr[i], arr[j]}});            }
        }

        sort(fractions.begin(), fractions.end());

        return {fractions[k - 1].second.first, fractions[k - 1].second.second};



        
    }
};
