/* Find Peak Element
arr[i] is the peak element : arr[i - 1] < arr[i] and arr[i + 1] < arr[i]
Find a peak element, and return its index
If the array contains multiple peaks, return the index to any of the peaks
*/

/* Brute Force Approach
check for ((i == 0 or arr[i-1] < arr[i]) and (i == n-1 or arr[i] > arr[i+1])) 

arr[i - 1] < arr[i] → it's greater than the left neighbor
If i == 0 → First element so there's no left neighbor

arr[i] > arr[i + 1] → it's greater than the right neighbor
If i == n-1 → Last element so there's no right neighbor

Time Complexity: O(N), N = size of the given array
*/

/* Optimal Approach : Binary Search
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            }

            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // low == high
        return low;
    }
};