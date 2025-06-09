/*
Given an array nums of size n, which denotes the positions of stalls
Integer k, which denotes the number of aggressive cows
Assign stalls to k cows such that the minimum distance between any two cows is the maximum possible
Find the maximum possible minimum distance
*/

class Solution {
   public:
    int aggressiveCows(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 1, high = nums.back() - nums.front(), ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int countCow = 1;
            int last = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] - last >= mid) {
                    countCow++;
                    last = nums[i];
                }
            }

            if (countCow >= k) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};