/*
If the given number, n is not a perfect square
Find the maximum number x, such that x squared is less than or equal to n (x*x <= n)
*/

// Brute Force: Using linear search
class Solution {
public:
    int mySqrt(int x) {
        long long i = 1;
        // Linear search on the answer space
        while (i * i <= x) {
            i++;
        }
        return i - 1;
    }
};

// Optimal Approach : Using in-built sqrt() function
int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}

// Optimal Approach : Using Binary Search
class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = mid * mid;
            if (val == x)
                return mid;

            if (val < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};