/*
Given: A list of package weights (array of integers)
An integer days, the number of days within which all packages must be shipped

Rules:
You must ship packages in order (i.e., can't reorder the array)
Each day ship has a fixed capacity (C), You can load packages until total weight exceeds C
Once the ship reaches its limit, you start the next day

Goal: 
Find Minimum ship capacity C such that all packages are shipped within exactly days or fewer
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int currWeight = 0;
            int reqDays = 1;

            for (int weight : weights) {
                if (currWeight + weight > mid) {
                    reqDays++;
                    currWeight = 0;
                }
                currWeight += weight;
            }

            if (reqDays <= days) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return ans;
    }
};