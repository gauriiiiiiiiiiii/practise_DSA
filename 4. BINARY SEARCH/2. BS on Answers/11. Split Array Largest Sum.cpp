/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized
Return the minimized largest sum of the split
A subarray is a contiguous part of the array
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int count = 1;
            int currentSum = 0;
            for (int i = 0; i < n; i++) {
                if (currentSum + nums[i] <= mid) {
                    currentSum += nums[i];
                } else {
                    count++;
                    currentSum = nums[i];
                }
            }

            if (count <= k) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};