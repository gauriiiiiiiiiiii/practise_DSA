/*
Given an integer array arr of size N, sorted in ascending order (with distinct values) 
Target value k
Array is rotated at some pivot point unknown to you
Find the index at which k is present and if k is not present return -1
*/

/*
Brute force : Linear search algorithm
Traverse the array to find the location of the target value

Time Complexity: O(N), N = size of the given array
Space Complexity: O(1)
*/ 

/*
Optimal Approach : Binary Search

Array is both Rotated + Sorted
Disruption in the sorting order affects the elimination process

Time Complexity: O(logN), N = size of the given array
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If mid points the target
            if (nums[mid] == target)
                return mid;

            // If Left part is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else
                    low = mid + 1;
            }

            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};

