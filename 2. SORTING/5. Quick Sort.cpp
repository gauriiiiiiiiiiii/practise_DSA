// Quick Sort - Pick a Pivot and place it in its Sorted Position

class Solution {
   public:

/*
1: Select pivot as the last element in the current subarray, pivot = nums[high]
2: Initialize index i = low - 1 , i tracks the last position of smaller elements
3: Loop j from low to high - 1
    For each nums[j], compare with pivot:
    If nums[j] < pivot:
        Increment i
        Swap nums[i] and nums[j] (This places the smaller element before the pivot zone)
4: After loop ends, place pivot in correct position:
    Swap nums[i + 1] and nums[high]
5: Return i + 1 as the partition index
*/

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return i + 1;
    }

/*
1: If low < high (at least two elements to sort)
2: Call partition(nums, low, high) to get pivot index `pi`
3: Recursively sort the left part: quickSortHelper(nums, low, pi - 1)
4: Recursively sort the right part: quickSortHelper(nums, pi + 1, high)
*/

    void quickSortHelper(vector<int>& nums, int low, int high) {
        if (low < high) {
            int pi = partition(nums, low, high);
            quickSortHelper(nums, low, pi - 1);
            quickSortHelper(nums, pi + 1, high);
        }
    }
    
/*
1: Call quickSortHelper(nums, 0, nums.size() - 1)
2: Return the sorted nums array
*/
    vector<int> quickSort(vector<int>& nums) {
        quickSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};

/*
Time Complexity
|   Best      | O(n log n) | Partition divides array into nearly equal halves recursively                 |
|   Average   | O(n log n) | On average, good partitioning leads to log n levels of recursion             |
|   Worst     | O(n²)      | Happens when pivot selection is poor (sorted array with first/last pivot)    |

Space Complexity
|   Space   | O(log n)   | Due to recursion stack in average/best case; O(n) in worst case (unbalanced)   |

❌ Stability - Not stable by default (equal elements may be reordered during partitioning)
✅ In-place - Does not need extra space for sorting (unlike Merge Sort)
❌ Adaptive - No	Doesn’t optimize on partially sorted arrays by default

- Divide and conquer algorithm
- Efficient in practice, usually Faster than Merge Sort
- Pivot choice and partitioning strategy affect performance
*/
