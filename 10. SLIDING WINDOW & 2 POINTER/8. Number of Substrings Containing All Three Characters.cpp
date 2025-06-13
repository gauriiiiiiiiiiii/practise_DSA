// Sliding Window 
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3, 0); 
        int l = 0, n = s.size(), count = 0;

        for(int r= 0; r<n;r++){
            freq[s[r] - 'a']++;

            while (freq[0]>0 && freq[1]>0 && freq[2]>0){
                    count += n - r;
                    freq[s[l] - 'a']--;
                    l++;
            }
        }
        
        return count;
    }
};

// Another Sol
class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0, n = s.size();
        int hash[3] = {-1, -1, -1};

        for (int i = 0; i < n; i++) {
            hash[s[i] - 'a'] = i;

            int mini = min(hash[0], min(hash[1], hash[2]));
            ans += mini + 1;
        }
        return ans;
    }
};