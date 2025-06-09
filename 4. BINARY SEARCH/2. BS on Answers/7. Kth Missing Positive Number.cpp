/*
Problem Statement :
You are given a sorted array arr of unique positive integers and an integer k
You need to return the kth missing positive number that's not in arr
*/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int missingCount = 0, current = 1, index = 0;

        while (missingCount < k) {
            if (index < arr.size() && arr[index] == current) {
                index++;
            } else {
                missingCount++;
                if (missingCount == k)
                    return current;
            }
            current++;
        }
        return current;
    }
};

