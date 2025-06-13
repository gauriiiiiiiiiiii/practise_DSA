class Solution {
public:
    int reverse(int x) {
        int sol = 0;
        while (x != 0) {
            int lastDigit = x % 10;
            x = x / 10;

            if (sol > INT_MAX / 10 || sol == INT_MAX && lastDigit > 7)
                return 0;
            if (sol < INT_MIN / 10 || sol == INT_MIN && lastDigit < -8)
                return 0;

            sol = sol * 10 + lastDigit;
        }
        return sol;
    }
};