/*
Problem Statement : 
Given an array nums of n integers, where nums[i] represents the number of pages in the i-th book
Integer m representing the number of students
Allocate all the books to the students so that each student gets at least one book
Each book is allocated to only one student, and the allocation is contiguous

Allocate the books to m students in such a way that the maximum number of pages assigned to a student is minimized
If the allocation of books is not possible, return -1
*/

class Solution {
   public:
    int findPages(vector<int> &nums, int m) {
        int n = nums.size();
        if (m > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int student = 1;
            int pages = 0;
            for (int i = 0; i < n; i++) {
                if (pages + nums[i] <= mid) {
                    pages += nums[i];
                } else {
                    student++;
                    pages = nums[i];
                }
            }

            if (student <= m) {
                ans = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }

        return ans;
    }
};