// Problem Statement:
// You're given a 0-indexed array nums. For each index i, you need to compute:
// The sum of absolute differences between i and all other indices j such that nums[i] == nums[j] and j != i
// If no such j exists, then arr[i] = 0

// Brute Force (O(n²)) 
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> arr(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j] && i != j) {
                    arr[i] += abs(i - j);
                }
            }
        }
        return arr;
    }
}; 

// Optimized (O(n)) (Using Hash Map + Prefix Sum)


