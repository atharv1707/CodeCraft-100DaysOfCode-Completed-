class Solution {
public:
    static bool compare(pair<int, int>& a, pair<int, int>& b){
        return a.second > b.second;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> leaderboard;

        for (int i = 0; i < score.size(); i++) {
            leaderboard.push_back({i, score[i]});
        }

        sort(leaderboard.begin(), leaderboard.end(), compare);

        vector<string> result(score.size());

        int ranking  = 1;

        for(const auto& pair : leaderboard){
            if(ranking == 1){
                result[pair.first] = "Gold Medal";
            }
            else if(ranking == 2){
                result[pair.first] = "Silver Medal";
            }
            else if(ranking == 3){
                result[pair.first] = "Bronze Medal";
            }
            else{
                result[pair.first] = to_string(ranking);
            }

            ranking++;
        }

        return result;
    }
};
