/* Selection Sort 
Select the minimum & Swap it 

Loop through the array from i = 0 to n-2
For each i, assume arr[i] is the smallest, set minIndex = i
Loop from j = i+1 to n-1 to find the true minimum element
After finding it, swap it with arr[i]
Repeat until the array is sorted
*/

class Solution {
   public:
    vector<int> selectionSort(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[min_idx]) {
                    min_idx = j;
                }
            }
            swap(nums[i], nums[min_idx]);
        }
        return nums;
    }
};


/*
Time Complexity
|   Best      | O(n²)      | Even if the array is already sorted, it still compares all pairs, No early exit  |
|   Average   | O(n²)      | Compares all elements in nested loops regardless of initial order                |
|   Worst     | O(n²)      | Same as average. Performs n(n−1)/2 comparisons                                   |

Space Complexity
|   Space   | O(1)       | It's an in-place sorting algorithm. Uses no extra space except a few variables  |

✅ Comparisons - Always happen regardless of input order
❌ Not adaptive - It doesn't speed up on nearly sorted arrays
❌ Stability - Not stable by default (If elements are equal, it may change their relative order)
✅ In-place - No extra space used, sorting is done within the original array
*/

