class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> losses;

        vector<int> allWin;
        vector<int> justOneLoss;


        for(const auto& pair : matches){
            int loser = pair[1];
            losses[loser]++;
        }

        for(const auto& pair : matches){
            int winner = pair[0];
            int loser = pair[1];

            if(losses.find(winner) == losses.end()){
                allWin.emplace_back(winner);
                losses[winner] += 2;
            }
            if(losses[loser] == 1){
                justOneLoss.emplace_back(loser);
            }
        }

        sort(allWin.begin(), allWin.end());
        sort(justOneLoss.begin(), justOneLoss.end());

        return {allWin, justOneLoss};
        
    }
};