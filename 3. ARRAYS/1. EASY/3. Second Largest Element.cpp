class Solution {
   public:
    int secondLargestElement(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return -1;

        // second smallest
        int small = INT_MAX;
        int second_small = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (arr[i] < small) {
                second_small = small;
                small = arr[i];
            } else if (arr[i] < second_small && arr[i] != small) {
                second_small = arr[i];
            }
        }

        return (second_small == INT_MAX) ? -1 : second_small;

        // second largest
        int large = INT_MIN;
        int second_large = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (arr[i] > large) {
                second_large = large;
                large = arr[i];
            } else if (arr[i] > second_large && arr[i] != large) {
                second_large = arr[i];
            }
        }

        return (second_large == INT_MIN) ? -1 : second_large;
    }
};