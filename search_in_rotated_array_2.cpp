class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Skip duplicates
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } 
            
            else if (nums[left] == nums[mid]) {
                left = mid + 1;
            } else if (nums[mid] == nums[right]) {
                right = mid - 1;
            } else {
                // Check if the left half is sorted
                if (nums[left] <= nums[mid]) {
                    if (target >= nums[left] && target < nums[mid]) {
                        right = mid - 1; // Search the left half
                    } else {
                        left = mid + 1; // Search the right half
                    }
                } else { // The right half is sorted
                    if (target > nums[mid] && target <= nums[right]) {
                        left = mid + 1; // Search the right half
                    } else {
                        right = mid - 1; // Search the left half
                    }
                }
            }
        }

        return false; // Target not found
    }
};
