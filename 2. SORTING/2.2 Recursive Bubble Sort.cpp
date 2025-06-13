class Solution {
public:
    void bubbleSortRecursive(vector<int>& nums, int n) {
        if (n == 1) return;    // Base case: if size is 1, it's already sorted

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);    // Bubble the largest element to the end
            }
        }

        bubbleSortRecursive(nums, n - 1);   // Recursive call for remaining unsorted part
    }

    vector<int> bubbleSort(vector<int>& nums) {
        bubbleSortRecursive(nums, nums.size());
        return nums;
    }
};
