// Prefix Sum + HashMap
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            if (prefixCount.find(sum - goal) != prefixCount.end()) {
                count += prefixCount[sum - goal];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};

// Sliding Window Approach
class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0)
            return 0;
        int l = 0, n = nums.size(), sum = 0, count = 0;

        for (int r = 0; r < n; r++) {
            sum += nums[r];

            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

