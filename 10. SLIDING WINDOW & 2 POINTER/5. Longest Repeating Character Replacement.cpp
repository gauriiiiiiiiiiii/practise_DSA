class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0, maxLen = 0, maxFreq = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            while ((r - l + 1) - maxFreq > k) {
                count[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

// Another Solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};
        int l = 0, r = 0, n = s.size(), maxLen = 0, maxFreq = 0;

        while (r < n) {
            hash[s[r] - 'A']++;
            maxFreq = max(maxFreq, hash[s[r] - 'A']);

            int changes = (r - l + 1) - maxFreq;
            if (changes > k) {
                hash[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};