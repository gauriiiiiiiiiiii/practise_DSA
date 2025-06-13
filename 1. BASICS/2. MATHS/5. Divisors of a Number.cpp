class Solution {
   public:
    vector<int> divisors(int n) {
        vector<int> result;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {  
                result.push_back(i);
                if (i != n / i) result.push_back(n / i); }
           
        }
        sort(result.begin(), result.end());
        return result;
    }
};

