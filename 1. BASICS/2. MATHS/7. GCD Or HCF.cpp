/*
GCD (Greatest Common Divisor) & HCF (Highest Common Factor) 
GCD/HCF of two or more integers is the largest number that divides all of them exactly (without leaving a remainder)
*/

// Brute Force
class Solution {
   public:
    int GCD(int n1, int n2) {
        int ans = 1;
        for (int i = 1; i <= min(n1, n2); i++) {
            if (n1 % i == 0 && n2 % i == 0) ans = i;
        }
        return ans;
    }
};

/*
Euclidean Algorithm 
The GCD of two numbers a and b is the same as the GCD of b and a % b
This repeats until b becomes 0. When b == 0, the GCD is a
*/

class Solution {
   public:
    int GCD(int n1, int n2) {
        while (n2 != 0) {
            int temp = n2;
            n2 = n1 % n2;
            n1 = temp;
        }
        return n1;
    }
};