/*
Given a string s, return the length of the longest substring without repeating characters

Approach:
Use a hash set (or hash map) to track characters in the current window
Move the right pointer to expand the window
If a duplicate is found, shrink the window from the left until it’s valid again
*/

// With unordered_set
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {

            while (charSet.count(s[right])) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};


// With vector<int> mp(256, -1)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mp(256, -1);
        int i = 0, j = 0, maxLen = 0;

        for (j = 0; j < s.size(); j++) {
            if (mp[s[j]] != -1 && mp[s[j]] >= i) {
                i = mp[s[j]] + 1;
            }
            mp[s[j]] = j;
            maxLen = max(maxLen, j - i + 1);
        }
        return maxLen;
    }
};


