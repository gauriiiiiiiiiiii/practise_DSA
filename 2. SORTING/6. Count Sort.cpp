// Count Sort 
class Solution {
public:
    vector<int> countingSort(vector<int>& nums) {
        if (nums.empty()) return nums;

        // 1: Find min and max
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        // 2: Create count array of size (max - min + 1)
        int range = maxVal - minVal + 1;
        vector<int> count(range, 0);

        // 3: Count the frequency of each number
        for (int num : nums) {
            count[num - minVal]++;
        }

        // 4: Reconstruct sorted array
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
| Best     | O(n + k)   | Traverse input + build count + reconstruct sorted array           |
| Average  | O(n + k)   | Efficient if range (k = max - min) is not large compared to n     |
| Worst    | O(n + k)   | Slower if k is very large (e.g., wide range, sparse input data)   |

Space Complexity
| Space    | O(k)       | Extra space for count array of size (max - min + 1)           |

❌ In-place - Requires auxiliary space (count array)
❌ Stability -  Without extra output array and prefix sums, it’s not stable    
✅ Efficient	- When k = max - min is small
✅ Negative nums	- Handled by offsetting with minVal
✅ Comparison-free - Doesn’t rely on element comparison
*/
