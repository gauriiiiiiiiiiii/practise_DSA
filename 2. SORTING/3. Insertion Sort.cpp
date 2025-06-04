/*
Loop through the array from i = 0 to n-1
For each i, set j = i
While j > 0 and arr[j - 1] > arr[j],
    Swap arr[j] and arr[j - 1]
    Decrement j by 1
This places the current element at its correct position in the sorted left part
Repeat until the array is sorted
*/

class Solution {
   public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j > 0 && nums[j - 1] > nums[j]) {
                swap(nums[j - 1], nums[j]);
                j--;
            }
        }
        return nums;
    }
};

/*

Time Complexity
| Case        | Complexity | Explanation                                                                     |
| ----------- | ---------- | ------------------------------------------------------------------------------- |
|   Best      | O(n)       | Array is already sorted; only one pass, no shifts needed                        |
|   Average   | O(n²)      | Elements may need to be shifted multiple times to insert in correct place       |
|   Worst     | O(n²)      | Array is reverse sorted; each insertion causes shifting of all previous elements|

✅ Adaptive — runs faster on nearly sorted arrays

Space Complexity
| Type      | Complexity | Explanation                                                                     |
| --------- | ---------- | --------------------------------------------------------------------------------|
|   Space   | O(1)       | In-place sorting, uses constant extra space for shifting elements               |

Stability: ✅ Stable (equal elements maintain their relative order)

*/


