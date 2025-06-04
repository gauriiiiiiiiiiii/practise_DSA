// Problem Statement:
// You are given a 0-indexed array nums of size n consisting of non-negative integers.
// You need to perform n - 1 operations on the array in the following way:

// For each index i from 0 to n - 2:
// If nums[i] == nums[i + 1], then Multiply nums[i] by 2, and Set nums[i + 1] to 0.
// Otherwise, do nothing.
// After performing all operations, move all 0’s to the end of the array while keeping the order of non-zero elements unchanged.
// Return the resulting array after all operations.

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] == nums[i]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        };

        int k = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                nums[k++] = nums[j];
            }
        }
        while (k < n) {
            nums[k++] = 0;
        }
        return nums;
    }
};



