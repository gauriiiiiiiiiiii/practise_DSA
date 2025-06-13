class Solution {
public:
    void insertionSortRecursive(vector<int>& nums, int n) {
        if (n <= 1)     // Base case: if the array has 1 or no element, it's already sorted
            return;

        insertionSortRecursive(nums, n - 1);    // Sort first n-1 elements

        int last = nums[n - 1];      // Insert last element at correct position
        int j = n - 2;

        while (j >= 0 && nums[j] > last) {   // Move elements greater than `last` one position ahead
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = last;
    }

    vector<int> insertionSort(vector<int>& nums) {
        insertionSortRecursive(nums, nums.size());
        return nums;
    }
};
