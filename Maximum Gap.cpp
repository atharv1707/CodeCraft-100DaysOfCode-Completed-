#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;


        vector<int> leftArray(nums.begin() + left, nums.begin() + left + n1);
        vector<int> rightArray(nums.begin() + mid + 1, nums.begin() + mid + 1 + n2);

        int i = 0;
        int j = 0;
        int k = left;

        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                nums[k++] = leftArray[i++];
            } else {
                nums[k++] = rightArray[j++];
            }
        }

        while (i < n1) {
            nums[k++] = leftArray[i++];
        }

        while (j < n2) {
            nums[k++] = rightArray[j++];
        }
    }

    void mergeSort(std::vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;

            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);

            merge(nums, left, mid, right);
        }
    }

    int maximumGap(std::vector<int>& nums) {
        int n = nums.size();

        if (n < 2) {
            return 0;
        }

        mergeSort(nums, 0, n - 1);

        int max_diff = -1;
        for (int i = 0; i < n - 1; i++) {
            int j = i + 1;
            if (nums[j] - nums[i] > max_diff) {
                max_diff = nums[j] - nums[i];
            }
        }

        return max_diff;
    }
};

