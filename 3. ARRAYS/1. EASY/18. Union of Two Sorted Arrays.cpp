// Using Map
class Solution {
   public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        map<int, int> freq;
        vector<int> unionArr;
        for (int i = 0; i < n; i++) freq[nums1[i]]++;
        for (int i = 0; i < m; i++) freq[nums2[i]]++;
        for (auto& it : freq) unionArr.push_back(it.first);
        return unionArr;
    }
        /* 
        it.first → the element (the number from the arrays)
        it.second → its frequency (how many times it appeared)
        */
};

// Using Set
class Solution {
   public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        set<int> s;
        vector<int> unionArr;
        for (int i = 0; i < n; i++) s.insert(a[i]);
        for (int i = 0; i < m; i++) s.insert(b[i]);
        for (auto &it : s) unionArr.push_back(it);
        return unionArr;
    }
};

// Two Pointers
class Solution {
   public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n = a.size();
        int m = b.size();
        int i = 0, j = 0;
        vector<int> result;

        while (i < n && j < m) {
            while (i > 0 && i < n && a[i] == a[i - 1]) i++;
            while (j > 0 && j < m && b[j] == b[j - 1]) j++;

            if (i >= n || j >= m) break;

            if (a[i] < b[j]) {
                result.push_back(a[i]);
                i++;
            } else if (a[i] > b[j]) {
                result.push_back(b[j]);
                j++;
            } else {
                result.push_back(a[i]);
                i++;
                j++;
            }
        }

        while (i < n) {
            if (i == 0 || a[i] != a[i - 1]) result.push_back(a[i]);
            i++;
        }

        while (j < m) {
            if (j == 0 || b[j] != b[j - 1]) result.push_back(b[j]);
            j++;
        }

        return result;
    }
};
