/*
Given two numbers N and M, find the Nth root of M
*/

/*
Brute Force Approach : Using Linear Search
Time Complexity: O(M)
*/

/*
Optimal Approach : Using Binary Search
Time Complexity: O(logN)
*/
class Solution {
   public:
    long long power(long long base, int exp, int limit) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
            if (result > limit) return result;
        }
        return result;
    }

    int NthRoot(int N, int M) {
        int low = 1, high = M;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long val = power(mid, N, M);

            if (val == M)
                return mid;
            else if (val < M)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
