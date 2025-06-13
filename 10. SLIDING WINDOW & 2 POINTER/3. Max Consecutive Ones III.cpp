/*
Problem Summary:
You’re given: A binary array nums (contains only 0 and 1)
An integer k = maximum number of 0s you can flip to 1

Return the length of the longest subarray containing only 1s after flipping at most k zeros
*/

// LONGEST SUBARRAY WITH ATMOST K ZEROS 

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, len = 0, maxLen = 0, zeroCount = 0;

        while (r < nums.size()) {
            if (nums[r] == 0)
                zeroCount++;

            if (zeroCount > k) {
                if (nums[l] == 0) {
                    zeroCount--;
                }
                l++;
            } else {
                len = r - l + 1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};


