class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> Result ;
        
        unordered_map<string, int> track;

        for(string c : words){
            track[c]++;
        }

        vector<pair<string, int>> maptoVec(track.begin(), track.end());

        sort(maptoVec.begin(), maptoVec.end(), [](const auto& a, const auto& b){
            return a.second>b.second || a.second == b.second && a.first< b.first;
        });

        for(int i = 0 ; i < k ; i++){
            Result.push_back(maptoVec[i].first);
        }

        return Result;
        
    }
};