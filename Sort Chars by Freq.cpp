class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freqMap;
        string result = "";

        for(char c : s){
            freqMap[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for(auto &pair : freqMap){
            maxHeap.push({pair.second, pair.first});
        }

        while(!maxHeap.empty()){
            auto top = maxHeap.top();
            maxHeap.pop();
            result += string(top.first, top.second);
        }

        


        return result;


        
    }
};

//approach 2 

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freqMap;
        string result = "";

        for(char c : s){
            freqMap[c]++;
        }

        //convert the map to a vector
        vector<pair<char, int>> vec(freqMap.begin(), freqMap.end());

        //custom sort function

        auto comparator = [](pair<char, int> &a, pair<char, int> &b){
            return a.second > b.second; 
        };

        sort(vec.begin(), vec.end(), comparator);

        for(auto &pair : vec){
            result += string(pair.second, pair.first);
        }

        


        return result;


        
    }
};