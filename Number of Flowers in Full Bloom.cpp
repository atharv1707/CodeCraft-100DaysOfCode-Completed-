class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        vector<int> start_time;
        vector<int> end_time;
        vector<int> result;

        for(auto i : flowers){
            start_time.push_back(i[0]);
            end_time.push_back(i[1]);
        }

        //to apply binary search
        sort(start_time.begin(), start_time.end());
        sort(end_time.begin(), end_time.end());

        for(int i : people){

            int canVisit = upper_bound(start_time.begin(), start_time.end(), i) - start_time.begin();
            int dead = lower_bound(end_time.begin(), end_time.end(), i) - end_time.begin();

            int ans = canVisit - dead;
            result.push_back(ans);
        }



        return result;
        
    }
};