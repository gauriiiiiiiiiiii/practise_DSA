/* Naive Recursion
Time Complexity: O(2^n) — exponential, because it recalculates the same subproblems multiple times
Stack Overflow Risk: Recursion can crash for larger n
*/ 
class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else
            return fib(n - 1) + fib(n - 2);
    }
};

/* Better: Constant Space Dynamic Programming
Time: O(n)
Space: O(1) 
No recursion → avoids stack overhead
No dp[] array → saves memory
Perfect for n up to 30 or even 10⁶
*/

class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int a = 0, b = 1;
        for (int i = 2; i <= n; i++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};