// Total number of occurrences = last occurrence - first occurrence + 1
// Time Complexity: O(2*logN), where N = size of the given array

class Solution {
public:
    int countOccurrences(vector<int>& nums, int target) {
        int firstIdx = first(nums, target);
        int lastIdx = last(nums, target);
        return (firstIdx == -1) ? 0: lastIdx - firstIdx + 1;
    }

    int first(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return first;
    }

    int last(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return last;
    }
};