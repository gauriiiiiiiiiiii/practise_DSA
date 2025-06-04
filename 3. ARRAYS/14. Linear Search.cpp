// In linear search input data need not to be in sorted
// Sequential search
// Time complexity: O(n)

class Solution {
   public:
    int linearSearch(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                return i;  // Return index immediately when found
            }
        }
        return -1;  // Return -1 if target not found
    }
};

