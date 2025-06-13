class Solution {
   public:
    bool isArmstrong(int n) {
        int noOfDigit = (int)(log10(n) + 1);
        int original = n;
        int num = 0;

        while (n > 0) {
            int lastDigit = n % 10;
            n = n / 10;
            num += pow(lastDigit,noOfDigit);
        }
        return original == num;
    }
};