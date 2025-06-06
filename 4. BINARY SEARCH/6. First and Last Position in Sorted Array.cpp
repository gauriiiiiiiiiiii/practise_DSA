class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstIdx = first(nums, target);
        int lastIdx = last(nums, target);
        return {firstIdx, lastIdx};
    }

//if (firstIdx == -1) return { -1, -1};

    int first(vector<int> nums, int target) {
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
    };

    int last(vector<int> nums, int target) {
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