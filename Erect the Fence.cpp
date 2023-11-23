class Solution {
public:
    int findValid(pair<int, int> &P1, pair<int, int> &P2, pair<int, int> P3){
        int x1 = P1.first;
        int y1 = P1.second;
        int x2 = P2.first;
        int y2 = P2.second;
        int x3 = P3.first;
        int y3 = P3.second;

        return ((y3-y2)*(x2-x1) - (y2-y1)*(x3-x2));

    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        vector<vector<int>> result;
        sort(trees.begin(), trees.end());

        deque<pair<int , int>> lower, upper;

        for(auto &point : trees){
            int l = lower.size();
            int u = upper.size();

            while( l >= 2 && findValid(lower[l-2], lower[l-1], {point[0], point[1]}) < 0){
                l--;
                lower.pop_back();
            }

            while( u >= 2 && findValid(upper[u-2], upper[u-1], {point[0], point[1]}) > 0){
                u--;
                upper.pop_back();
            }

            upper.push_back({point[0], point[1]});
            lower.push_back({point[0], point[1]});
        }

        

        set<pair<int, int>> st;
        for(auto &pair : upper){
            st.insert(pair);
        }

        for(auto &pair : lower){
            st.insert(pair);
        } 

        for(auto &pair : st){
            result.push_back({pair.first, pair.second});
        }


        return result;
    }
};