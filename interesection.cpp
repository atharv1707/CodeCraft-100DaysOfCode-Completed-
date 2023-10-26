class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2); // Make sure nums1 is the smaller array
        }

        unordered_set<int> result_set;

        for (int num : nums1) {
            if (find(nums2.begin(), nums2.end(), num) != nums2.end()) {
                result_set.insert(num);
            }
        }

        vector<int> result(result_set.begin(), result_set.end());
        return result;
    }
};
