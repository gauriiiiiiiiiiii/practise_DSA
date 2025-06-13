/*
Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings
If there is no common prefix, return an empty string ""
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty())
                    return "";
            }
        }

        return prefix;
    }
};

/*
1) Check if the input list is empty : If strs has no strings, return an empty string immediately
2) Initialize prefix with the first string : Assume the first word is the common prefix
3) Loop through the rest of the strings : Start from the second string (i = 1) and compare each one with the current prefix.
4) Check if the current string starts with the prefix
Using find(prefix) != 0 means prefix is not at the start of the current string
If this is true, keep trimming the prefix from the end (by removing the last character)
Trim prefix until it matches the start of the current string
5) Keep removing the last character of prefix until : It matches the beginning of the current string or It becomes empty
6) If prefix becomes empty, return "" : Means there is no common prefix among the strings
7) After checking all strings, return the final prefix
*/