// Problem Statement: Given a sorted array nums, remove duplicates such that each unique element appears at most twice while maintaining the original order. Return the new length k of the modified array. The first k elements of nums should contain the final result (with duplicates removed beyond twice), and the remaining elements can be ignored.

// Key Points:
// Sorted Array: The input array is already sorted in non-decreasing order, so duplicates are adjacent
// In-place Modification: The solution must modify the array in-place without using extra space (O(1) memory)
// At Most Two Duplicates: Each unique element can appear at most twice in the final array
// Relative Order: The order of elements should remain unchanged after removal

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int k = 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

