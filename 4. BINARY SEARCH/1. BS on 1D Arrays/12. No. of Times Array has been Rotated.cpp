/*
Given an integer array arr of size N, sorted in ascending order with distinct elements
The array has been rotated an unknown number of times (between 1 and N)
Find the minimum element in the array
The index of the minimum element is equal to the number of times the array has been rotated

Number of rotations in an array is equal to the index(0-based index) of its minimum element
*/

/*
Brute Force Approach

Time Complexity: O(N), N = size of the given array
Space Complexity: O(1)
*/
class Solution {
   public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int ans = INT_MAX;
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] < ans) {
                ans = arr[i];
                idx = i;
            }
        }
        return idx;
    }
};

/*
Optimal Approach : Using Binary Search

Time Complexity: O(logN), N = size of the given array
Space Complexity: O(1)
*/ 

class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            // If the subarray is already sorted
            if (arr[low] <= arr[high])
                return low;  // The smallest element index

            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            // Check if mid is the pivot
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
                return mid;

            // Decide which half to go
            if (arr[mid] >= arr[low])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return 0;  // Default return if not rotated
    }
};
