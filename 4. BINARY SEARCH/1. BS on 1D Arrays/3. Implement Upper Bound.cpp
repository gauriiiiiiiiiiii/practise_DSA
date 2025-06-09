/*
Upper bound finds the first or the smallest index in a sorted array where the value at that index 
is greater than the given key i.e. x

The upper bound is the smallest index, ind, where arr[ind] > x
But if any such index is not found, the upper bound algorithm returns n (size of given array)

Lower bound the condition was arr[ind] >= x and Upper bound,  arr[ind] > x
*/

// Naive approach (Using linear search)

// Optimal Approach (Using Binary Search):
class Solution {
   public:
    int upperBound(vector<int> &nums, int x) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ub = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > x) {
                ub = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ub;
    }
};