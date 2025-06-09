/*
Floor of x is the largest element in the array which is smaller than or equal to x
Ceiling of x is the smallest element in the array greater than or equal to x
If no floor or ceil exists, output -1
*/

class Solution {
   public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int floor = findFloor(nums, x);
        int ceil = findCeil(nums, x);
        return {floor, ceil};
    }

    int findFloor(vector<int> nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int floor = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= x) {
                floor = nums[mid];
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return floor;
    }

    int findCeil(vector<int> nums, int x) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ceil = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= x) {
                ceil = nums[mid];
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ceil;
    }
};