/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray mountainArr, int l, int r, int target) {
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return -1;
    }

    int reverseBinarySearch(MountainArray mountainArr, int l, int r, int target) {
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            
            if (mountainArr.get(mid) == target) {
                return mid;
            } else if (mountainArr.get(mid) > target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return -1;
    }

    int findPeak(MountainArray &mountainArr) {
        int start = 0;
        int end = mountainArr.length() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;  
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIndex = findPeak(mountainArr);
        int idx = binarySearch(mountainArr, 0, peakIndex, target);

        if (idx == -1) {
            return reverseBinarySearch(mountainArr, peakIndex, n - 1, target);
        }

        return idx;
    }
};
