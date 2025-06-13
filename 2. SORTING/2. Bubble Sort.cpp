/* Bubble Sort 
Push the Max to Last by Adjacent Swaps 

Loop through the array from i = n-1 to 1
For each i, compare all adjacent elements from j = 0 to i-1
If arr[j] > arr[j+1], swap them
The largest element "bubbles up" to index i
Repeat the process until the array is sorted
If no swaps are made in a pass, array is already sorted
*/

class Solution {
   public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--) {
            int didSwap = 0;
            for (int j = 0; j <= i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    didSwap = 1;
                }
            }
            if (didSwap == 0) {
                break;
            }
        }
        return nums;
    }
};

/* 
Time Complexity
|   Best      | O(n)       | If the array is already sorted, only one pass is needed with no swaps        |
|   Average   | O(n²)      | Nested loops compare and swap elements until the array is sorted             |
|   Worst     | O(n²)      | Array is reverse sorted; every possible swap happens                         |

Space Complexity
|   Space   | O(1)       | In-place algorithm with only a few extra variables for swapping and flags     |

✅ Adaptive - Stops early if no swaps in a pass (array already sorted)
✅ Comparision - Can be faster than Selection Sort on nearly sorted arrays
✅ Stability - Stable (equal elements maintain their relative order)
✅ In-place - No extra memory needed beyond a few variables
*/

// Accessing an Index that is not present causes an runtime error
