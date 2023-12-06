

class Solution {
public:
    int peakIndexInMountainArray(std::vector<int>& arr) {
        int n = arr.size();
        int start = 0 ; 
        int end = n - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid == 0 || mid == n - 1) {
                return mid;
            }

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                ans = mid;
                break;  // You found the peak, so exit the loop
            }

            if (arr[mid - 1] < arr[mid]) {
                // ascending part
                start = mid + 1;
            } else if (arr[mid] > arr[mid + 1]) {
                end = mid ;
            }
        }

        return ans;
    }
};