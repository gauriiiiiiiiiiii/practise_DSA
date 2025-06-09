/*
Given an integer array arr of size N, sorted in ascending order with distinct elements
The array has been rotated an unknown number of times (between 1 and N)
Find the minimum element in the array

The index of the minimum element is equal to the number of times the array has been rotated
*/

/*
Brute force : Linear Search

Time Complexity: O(N), N = size of the given array
Reason: We have to iterate through entire array to check if the target is present in array

Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minElement = INT_MAX;
        for (int i = 0; i < n; i++) {
            minElement = min(nums[i], minElement);
        }
        return minElement;
    }
};

/*
Optimal Approach : Binary Search

If an array is rotated and sorted
For every index, one of the 2 halves of the array will always be sorted

Time Complexity: O(logN), N = size of the given array
Space Complexity: O(1)

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Search Space is sorted
            if (nums[low] <= nums[high]) {
                return ans = min(ans, nums[low]);
                break;
            }

            // Left Part is Sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]); // Keep the min
                low = mid + 1;             // Eliminate left half
            }
            // Right Part is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};