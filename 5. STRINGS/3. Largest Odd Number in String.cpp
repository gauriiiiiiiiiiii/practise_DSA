/*
You are given a string num, representing a large integer
Return the largest-valued odd integer (as string) that is a non-empty substring of num, or an empty string "" if no odd integer exists
Substring is a contiguous sequence of characters within a string
*/

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length() - 1; i >= 0; i--) {
            if ((num[i] - '0') % 2 == 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};


/*
Start checking from the last digit of the string
Look for the first odd digit (1, 3, 5, 7, or 9) while moving backward
As soon as you find an odd digit, take the substring from the beginning up to that digit
Return this substring — it's the largest odd number possible
If no odd digit is found, return an empty string
*/