class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int bouquet = 0, flower = 0;
            for (int bloom : bloomDay) {
                if (bloom <= mid) {
                    flower++;
                    if (flower == k) {
                        bouquet++;
                        flower = 0;
                    }
                } else {
                    flower = 0;
                }
            }

            if (bouquet >= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
