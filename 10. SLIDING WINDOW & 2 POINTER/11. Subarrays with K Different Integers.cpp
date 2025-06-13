class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0, n = nums.size(), count = 0;

        for (int r = 0; r < n; r++) {
            if (freq[nums[r]] == 0)
                k--;

            freq[nums[r]]++;

            while (k < 0) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0)
                    k++;
                l++;
            }
            count += r - l + 1;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};