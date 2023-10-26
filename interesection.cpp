
//approach 1 :  using sets

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result_set;

        for(int num : nums2){
            if(set1.count(num)){
                result_set.insert(num);
                

            }
        }
        vector<int> result(result_set.begin(), result_set.end()); 
        return result;

        
    }
};


//approach 2 using maps


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_map < int, int> freq;
        vector<int> result;

        for(int i : nums1){
            freq[i] = 1; //to maintain unique element

        }

        for(int num : nums2){
            if(freq[num] ==1){
                //if it is present in the map we made above and frequency is 1
                result.push_back(num);
                freq[num] = -1 ; //mark them 0 to avoid any repetition 
            }
        }

        return result;




        
    }
};
