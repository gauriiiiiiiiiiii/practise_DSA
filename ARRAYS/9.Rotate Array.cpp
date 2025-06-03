class Solution {
public:
    // RIGHT ROTATE
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // Handle cases where k > n
        k = k % n;
        // Reverse the entire array
        reverse(nums.begin(), nums.end());
        // Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // Reverse the remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};