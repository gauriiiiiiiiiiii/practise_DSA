class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Check if the input vector is empty
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size(); 
        int k = 0; //Track the position of the last unique element

        for (int i = 1; i < n; i++) {
            // If current element is different from the last unique element
            if (nums[i] != nums[k]) {
                k++;  
                nums[k] = nums[i];  
            }
        }

        // Return the count of unique elements 
        return k + 1;
    }
};

