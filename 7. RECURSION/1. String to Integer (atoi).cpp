/*
Problem Statement :
You are given a string s, You need to convert it into a 32-bit signed integer similar to the C/C++ function atoi()

Ignore Leading Whitespace: Skip any spaces at the beginning

Check for Sign (+ or -) : After spaces, check if the first non-space character is + or -, If not, the number is positive by default

Convert Digits Until Invalid Character : Read and store characters as long as they are digits

Ignore Leading Zeros

Handle 32-bit Integer Overflow : Final result must be in range: [-2^31, 2^31 - 1] = [-2147483648, 2147483647]
Clamp it if it goes out of bounds: If less than -2147483648, return -2147483648, If more than 2147483647, return 2147483647
*/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length(), sign = 1;
        long long result = 0;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : +1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return static_cast<int>(sign * result);
    }
};