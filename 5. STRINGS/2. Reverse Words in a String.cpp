/*
Given an input string s, reverse the order of the words
A word is defined as a sequence of non-space characters
The words in s will be separated by at least one space
Return a string of the words in reverse order concatenated by a single space
Note that s may contain leading or trailing spaces or multiple spaces between two words
The returned string should only have a single space separating the words
Do not include any extra spaces
*/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0, n = s.length();

        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            int j = i;
            while (j < n && s[j] != ' ')
                j++;

            words.push_back(s.substr(i, j - i));
            i = j;
        }

        string result;
        for (int k = words.size() - 1; k >= 0; k--) {
            result += words[k];
            if (k > 0)
                result += ' ';
        }
        return result;
    }
};

/*
1) Skip and extract words
Traverse the string s character by character
Ignore leading and extra spaces
When a word is found (sequence of non-space characters), store it in a vector<string>

2) Store words
Use substr(i, j - i) to extract each word and store it in the words vector

3) Build result in reverse
Loop through the words vector backwards (from last to first)
Append each word to the result string
Add a single space between words (but not after the last one)

4) Return the final string
The result contains words in reverse order, with exactly one space between them and no extra spaces
*/