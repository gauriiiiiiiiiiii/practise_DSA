class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), oddCount = 0, count = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] % 2 == 1)
                oddCount++;
            while (oddCount > k) {
                if (nums[l] % 2 == 1)
                    oddCount--;
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};