

//keep an eye on first elements because it is sorted and look where can we move to get equal elements. If not possible, return -1.


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int res = -1; // Initialize res to -1 in case there's no common element.

        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2

        while (i < nums1.size() && j < nums2.size()) {
            int num1_smol = nums1[i]; // Element from nums1
            int num2_smol = nums2[j]; // Element from nums2

            if (num1_smol == num2_smol) {
                return num1_smol; // Found a common element, return it.
            } else if (num1_smol < num2_smol) {
                i++; // Move the pointer in nums1 because num1 is smaller.
            } else {
                j++; // Move the pointer in nums2 because num2 is smaller.
            }
        }

        return res; // No common element found, return -1.
    }
};



//approach 2 : using set , basically making set out one vector and iterating on other checking if current element is present int in the set or not


class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        unordered_set< int> res(nums1.begin(), nums1.end());

        for(int num : nums2){
            if(res.count(num)){
                //basically checking if it is the set or not
                return num;
            }
        }

        return -1;


        
    }
};
