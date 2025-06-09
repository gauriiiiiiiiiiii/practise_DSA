/*
Sum of first N numbers(S1) = (N*(N+1))/2
Sum of all array elements(S2) 
The missing number = S1-S2
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = (n*(n + 1))/2;

        int actualSum = 0;
        for (int i = 0; i < n; i++) {
            actualSum += nums[i];
        }

        return expectedSum - actualSum;
    }
};

/*
XOR of two same numbers is always 0 (a ^ a = 0) ← Property 1.
XOR of a number with 0 will result in the number itself (0 ^ a = a) ← Property 2

XOR all the numbers between 1 to N ( xor1 = 1^2^.......^N )
XOR all the numbers in the given array (xor2 = 1^2^......^N) (contains all the numbers except the missing one).

XOR between xor1 and xor2 ( xor1 ^ xor2 = (1^1)^(2^2)^........^(missing Number)^.....^(N^N) )
All the numbers except the missing number will form a pair 
Result will be = 0 ^ (missing number) = missing number
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < n; i++) {
            xor2 ^= nums[i];
            xor1 ^= (i);
        }
        xor1 = xor1 ^ n;
        return (xor1 ^ xor2);
    }
};

