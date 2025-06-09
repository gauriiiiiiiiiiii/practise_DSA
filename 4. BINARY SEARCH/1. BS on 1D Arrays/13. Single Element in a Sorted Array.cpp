/*
Sorted array consisting of only integers where every element appears exactly twice
Except for one element which appears exactly once
Return the single element that appears only once
*/

/* Brute force 
if ( arr[i] != arr[i-1] and arr[i] != arr[i+1] ) return arr[i];

Edge Cases
if n == 1 : Array size is 1 : Return that single element 
if i == 0: First element of the array : Only Condition to Check is: arr[i] != arr[i+1]
if i == n-1: Last element of the array : Check if: arr[i] != arr[i-1]

Time Complexity: O(N), N = size of the given array
Space Complexity: O(1) 
*/

/* Brute force 
Using XOR  ( a ^ a = 0 , a ^ 0 = a )

    int n = arr.size(); 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = ans ^ arr[i];
    }
    return ans;
*/

/*
Optimal Approach : Binary Search

Edge cases:
If n == 1: Array size is 1 : return that single element 
If arr[0] != arr[1]: First element of the array : return arr[0]
If arr[n-1] != arr[n-2]: Last element of the array :  return arr[n-1]

If arr[mid] != arr[mid-1] and arr[mid] != arr[mid+1] : return arr[mid]

If (i % 2 == 0 and arr[i] == arr[i+1]) or (i%2 == 1 and arr[i] == arr[i-1]), we are in the left half
If (i % 2 == 0 and arr[i] == arr[i-1]) or (i%2 == 1 and arr[i] == arr[i+1]), we are in the right half

If we are in the left half, eliminate it as our single element appears on the right : low = mid+1
If we are in the right half, eliminate it as our single element appears on the left : high = mid-1

Time Complexity: O(logN)
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            if ((nums[mid] == nums[mid - 1] && mid % 2 == 1) ||
                (nums[mid] == nums[mid + 1] && mid % 2 == 0)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
