// 
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lSum = 0, rSum = 0, MaxSum = 0, rightIdx = n - 1;

        for (int i = 0; i < k; i++) {
            lSum += cardPoints[i];
        }
        MaxSum = lSum;

        for (int i = k - 1; i >= 0; i--) {
            lSum -= cardPoints[i];
            rSum += cardPoints[rightIdx];
            rightIdx--;
            MaxSum = max(MaxSum, lSum + rSum);
        }
        return MaxSum;
    }
};

// Another Sol.
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(), lSum = 0, rSum = 0, maxSum = 0;

        for (int i = 0; i < k; i++) {
            lSum += cardPoints[i];
        }
        maxSum = lSum;

        for (int i = 0; i < k; i++) {
            lSum -= cardPoints[k - 1 - i];
            rSum += cardPoints[n - 1 - i];
            maxSum = max(maxSum, lSum + rSum);
        }
        return maxSum;
    }
};

/*
lSum -= cardPoints[k - 1 - i];  // remove one card from left
rSum += cardPoints[n - 1 - i];  // add one card from right
*/