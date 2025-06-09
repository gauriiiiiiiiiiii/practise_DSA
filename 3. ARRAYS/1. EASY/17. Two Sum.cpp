// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target

// Brute Force Approach: O(n^2) time complexity
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Hash Map Approach: O(n) time complexity
