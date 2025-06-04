class Solution {
   public:
    int largestElement(vector<int>& arr) {
        // Brute Force Approach
        sort(arr.begin(), arr.end());
        return arr[arr.size() - 1];

        // Recursive Approach
        int max = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            if (max < arr[i]) {
                max = arr[i];
            }
        }
        return max;
    }
};


