class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int k = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }

        // Fill remaining positions with zeros
        while (k < n) {
            nums[k++] = 0;
        }
    }
};

// Using 2 pointers
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        // Find the first zero
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        // If no zeros found, return
        if (j == -1) return;

        // Move non-zero elements to the front
        for (int i = j + 1; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};