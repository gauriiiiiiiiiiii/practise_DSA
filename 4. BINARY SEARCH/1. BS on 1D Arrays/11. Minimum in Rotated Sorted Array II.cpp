/*
Given the sorted rotated array nums that may contain duplicates
Return the minimum element of this array

Best/Average Case: O(log n)
Worst Case (many duplicates): O(n)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Right half is sorted, Min must lie in the Left half or at Mid
            if (nums[mid] < nums[high]) {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }

            // Left half is sorted, min must lie in the Right half or at Mid
            else if (nums[mid] > nums[high]) {
                ans = min(ans, nums[mid]);
                low = mid + 1;
            }
            // Duplicates , Cautiously reduce the search space
            else {
                ans = min(ans, nums[mid]);
                high--;
            }
        }
        return ans;
    }
};