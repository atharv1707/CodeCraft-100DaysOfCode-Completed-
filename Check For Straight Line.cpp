//checking slope of each with first set of slope to see if it is constant or not


class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {

        bool isStraight = true;
        int dy = c[1][1] - c[0][1];
        int dx = c[1][0] - c[0][0]; //we handled first two coordinates here


        for(int i = 2 ; i < c.size() ; i++){
            int dy_i = c[i][1] - c[0][1];
            int dx_i = c[i][0] - c[0][0];

            if((dy  * dx_i) != (dx * dy_i)){
                return false;
            }

        }

        return isStraight;



        
    }
};




