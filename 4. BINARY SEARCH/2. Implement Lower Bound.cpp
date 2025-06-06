/*
Lower bound is the smallest index, ind, where arr[ind] >= x 
Returns the index of the first element in the sorted array that is greater than or equal to x
But if any such index is not found, the lower bound algorithm returns n (size of given array)
*/

/* 
Brute Force Approach : Linear search algorithm 
Time Complexity: O(N), where N = size of the array (Worst case Traverse the whole array )
Space Complexity: O(1) as we are using no extra space
*/
class Solution {
   public:
    int lowerBound(vector<int> &nums, int x) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= x) return i;
        }
        return n;
    }
};

/*
Optimal Approach : Binary Search
Time Complexity: O(logN), where N = size of the given array
Space Complexity: O(1) as we are using no extra space
*/
class Solution {
   public:
    int lowerBound(vector<int> &nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int lb = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x) {
                lb = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return lb;
    }
};