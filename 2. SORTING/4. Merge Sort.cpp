// Merge Sort : Divide & Merge 

/* merge(nums, left, mid, right)
1: Find sizes of two subarrays to be merged
        n1 = mid - left + 1
        n2 = right - mid
2: Create temporary arrays L[0...n1-1] and R[0...n2-1]
        Copy data to L[] from nums[left to mid]
        Copy data to R[] from nums[mid+1 to right]
3: Initialize three pointers: i = 0, j = 0, k = left
        i for L[], j for R[], k for nums[]
4: While both i < n1 and j < n2
        Compare L[i] and R[j]:
            If L[i] <= R[j], set nums[k] = L[i], increment i & increment k
            Else set nums[k] = R[j], increment j & increment k
5: Copy any remaining elements of L[] (if any) into nums[]
6: Copy any remaining elements of R[] (if any) into nums[]
*/

class Solution {
   public:
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; i++) L[i] = nums[left + i];
        for (int j = 0; j < n2; j++) R[j] = nums[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j])
                nums[k++] = L[i++];
            else
                nums[k++] = R[j++];
        }
        while (i < n1) nums[k++] = L[i++];
        while (j < n2) nums[k++] = R[j++];
    }
/* mergeSortHelper(nums, left, right)
If left >= right, return (base case: only one element)
Find mid = (left + right) / 2
Recursively sort the left half: mergeSortHelper(nums, left, mid)
Recursively sort the right half: mergeSortHelper(nums, mid + 1, right)
Merge the two sorted halves: merge(nums, left, mid, right)
*/
    void mergeSortHelper(vector<int>& nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSortHelper(nums, left, mid);
        mergeSortHelper(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }
/* mergeSort(nums)
Main function that starts the recursion
Call helper : mergeSortHelper(nums, 0, nums.size() - 1)
*/
    vector<int> mergeSort(vector<int>& nums) {
        mergeSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};

/*
Time Complexity
|   Best      | O(n log n) | Divides the array and merges sorted halves efficiently every time              |
|   Average   | O(n log n) | Consistently divides and merges regardless of input order                      |
|   Worst     | O(n log n) | Same as average; stable O(n log n) time complexity for all cases               |

Space Complexity
|   Space   | O(n)       | Requires extra space proportional to input size for merging temporary arrays   |

✅ Stability - Stable (maintains relative order of equal elements)
❌ In-Place - Needs O(n) extra space

Efficient for large datasets
Recursive implementation 
*/

