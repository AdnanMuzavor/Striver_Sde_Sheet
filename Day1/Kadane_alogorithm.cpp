/*
53. Maximum Subarray
Medium

24112

1138

Add to List

Share
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.



Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Example 2:

Input: nums = [1]
Output: 1
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curr_max = -1e9;
        int final_max = -1e9;
        for (int i = 0; i < nums.size(); i++)
        {
            // We can eithe continue with prev_Sum if max
            // Else we can simply start with current element eliminating
            // prev sub array
            curr_max = max(nums[i], curr_max + nums[i]);
            // Update answer to maximum every time
            final_max = max(final_max, curr_max);
        }
        return final_max;
    }
};