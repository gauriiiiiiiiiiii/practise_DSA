/*
Counting Sort Algorithm
1. Find the min and max in the array
2. Create count array of size (max - min + 1)
3. Count the frequency of each number
4. Reconstruct the sorted array using the count array
*/

class Solution {
public:
    vector<int> countingSort(vector<int>& nums) {
        if (nums.empty()) return nums;

        // Step 1: Find min and max
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        // Step 2: Create count array
        int range = maxVal - minVal + 1;
        vector<int> count(range, 0);

        // Step 3: Count occurrences
        for (int num : nums) {
            count[num - minVal]++;
        }

        // Step 4: Reconstruct sorted array
        int index = 0;
        for (int i = 0; i < range; i++) {
            while (count[i]-- > 0) {
                nums[index++] = i + minVal;
            }
        }

        return nums;
    }
};

/*
Time Complexity
| Case     | Complexity | Explanation                                                       |
|----------|------------|-------------------------------------------------------------------|
| Best     | O(n + k)   | Traverse input + build count + reconstruct sorted array           |
| Average  | O(n + k)   | Efficient if range (k = max - min) is not large compared to n     |
| Worst    | O(n + k)   | Slower if k is very large (e.g., wide range, sparse input data)   |

Space Complexity
| Type     | Complexity | Explanation                                                   |
|----------|------------|---------------------------------------------------------------|
| Space    | O(k)       | Extra space for count array of size (max - min + 1)           |
| In-place | ❌ No     | Not in-place due to extra count array                          |

Stability
| Property | Description                                                                 |
|----------|-----------------------------------------------------------------------------|
| Stable?  | ❌ Not stable by default (may change relative order of equal elements)      |
| Fix?     | ✅ Can be made stable with prefix sum and auxiliary output array            |
*/
