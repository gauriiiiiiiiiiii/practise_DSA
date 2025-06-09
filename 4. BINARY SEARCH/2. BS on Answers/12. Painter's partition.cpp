/*
Given an array/list of length ‘N’
where the array/list represents the boards
and each element of the given array/list represents the length of each board
Some ‘K’ numbers of painters are available to paint these boards
Consider that each unit of a board takes 1 unit of time to paint
you are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards 
under the constraint that any painter will only paint the continuous sections of boards
*/

class Solution {
public:
    int splitArray(vector<int>& boards, int k) {
        int n = boards.size();
        int low = *max_element(boards.begin(),boards.end());
        int high = accumulate(boards.begin(),boards.end(),0);
        int ans = -1;

        while (low<=high){
            int mid = low + (high - low)/2;
            
            int noOfPainter = 1;
            int noOfBoards = 0;
            for(int i = 0;i<n;i++){
                if(noOfBoards + boards[i] <= mid){
                    noOfBoards += boards[i];
                } else {
                    noOfPainter++;
                    noOfBoards = boards[i];
                }
            }

            if (noOfPainter <= k){
                ans = mid;
                high = mid -1;
            }else low = mid + 1;
        }
       return ans;
    }
};

// Time Complexity: O(N log S) where: N = number of boards, S = sum of board lengths
