/*
Given positions of baskets and m balls
Place the m balls in the baskets such that the smallest distance (magnetic force) between any two balls is as big as possible
Return that maximum possible minimum distance
*/

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1, high = position.back() - position.front();
        int ans = 0, n = position.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int balls = 1;
            int last = position[0];
            for (int i = 1; i < n; i++) {
                if (position[i] - last >= mid) {
                    balls++;
                    last = position[i];
                    if (balls == m)
                        break;
                }
            }

            if (balls >= m) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }
};