class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {

        int time = 0;
        int n = colors.size();
        

        for(int i = 0 ; i < n-1; i++){

            if(colors[i] == colors[i+1]){
                time += min(neededTime[i],neededTime[i+1]);

                if(neededTime[i] > neededTime[i+1]){
                swap(neededTime[i], neededTime[i+1]);
            }
            }

           

        }



        return time;
        
    }
};