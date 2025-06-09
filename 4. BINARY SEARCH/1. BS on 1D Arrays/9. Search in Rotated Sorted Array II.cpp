/*
Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) 
Target value k
Array is rotated at some pivot point unknown to you
Return True if k is present and otherwise, return False
*/

/*
Brute force : Linear search algorithm

Time Complexity: O(N), N = size of the given array
*/

/*
Optimal Approach : Binary Search

Time Complexity: 
O(logN) for the best and average case
O(N/2) for the worst case Here, N = size of the given array
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            // If duplicates at boundaries and mid
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                if (nums[low] == target) return true;
                low++;
                if (nums[high] == target) return true;
                high--;
                continue;
            }

            // Left Part is Sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right Part is Sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

