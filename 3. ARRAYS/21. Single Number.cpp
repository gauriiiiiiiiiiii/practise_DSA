// Using XOR 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int a = 0;
        for (int i = 0; i < n; i++) {
            a ^= nums[i];
        }
        return a;
    }
}; 

// Using Map
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }

        for (auto& it : mpp) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return -1;
    }
};
