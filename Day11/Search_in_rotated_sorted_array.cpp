/*
33. Search in Rotated Sorted Array
Medium
18.5K
1.1K
Companies
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // If we found the target, no hustle, returjn it
            if (nums[mid] == target)
                return mid;
            // Check if left array is sorted
            if (nums[low] <= nums[mid])
            {
                // If yes check if target exists in that range
                if (nums[low] <= target && nums[mid] >= target)
                {
                    // In this case this is our sorted window so reduce high
                    high = mid - 1;
                }
                // if target doesnt lies in the window, search in other window
                else
                {
                    low = mid + 1;
                }
            }
            // left side not sorted hence right side is sorted
            else
            {
                // check if target can exists in sorted window
                if (target >= nums[mid] && target <= nums[high])
                    low = mid + 1;
                // else search in other window as thats the only option
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};