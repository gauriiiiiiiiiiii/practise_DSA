/* 
Binary search is only applicable in a sorted search space

In binary search, we generally divide the search space into two equal halves and then try to 
locate which half contains the target. According to that, we shrink the search space size

Time complexity is O(logN) where N = size of the given array
*/

// Iterative Implementation
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};

// Recursive Implementation
class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        int n = nums.size();

        if (low > high)
            return -1;

        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return binarySearch(nums, low, mid - 1, target);
        else
            return binarySearch(nums, mid + 1, high, target);
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};


