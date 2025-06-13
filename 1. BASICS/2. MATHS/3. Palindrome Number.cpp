class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int original = x;
        int reversed = 0;

        while (x != 0) {
            int lastDigit = x % 10;
            x = x / 10;

            if (reversed > INT_MAX / 10 || reversed == INT_MAX && lastDigit > 7)
                return 0;

            reversed = reversed * 10 + lastDigit;
        }

        return original == reversed;
    }
};

