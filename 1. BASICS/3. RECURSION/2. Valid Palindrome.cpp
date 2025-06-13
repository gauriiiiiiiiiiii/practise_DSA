class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) l++;
            while (l < r && !isalnum(s[r])) r--;

            if (tolower(s[l]) != tolower(s[r])) return false;

            l++;
            r--;
        }
        return true;
    }
};


// 
class Solution {
public:
    bool checkPalindrome(int i,string s) {
        if (i >= s.size() / 2)
            return true;
        if (s[i] != s[s.size() - 1 - i])
            return false;
        return checkPalindrome(i + 1, s);
    }
};