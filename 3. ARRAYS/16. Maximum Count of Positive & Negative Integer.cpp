class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int neg = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos = pos + 1;
            } else if (nums[i] < 0) {
                neg = neg + 1;
            }
        }
        return max(pos, neg);
    }
};

