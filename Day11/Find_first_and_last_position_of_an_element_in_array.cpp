/*
34. Find First and Last Position of Element in Sorted Array
Medium
14.6K
357
Companies
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
Accepted
1.4M
Submissions
3.3M
Acceptance Rate
41.6%
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> op;
        int low = 0, high = n - 1, lindex = -1, hindex = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // if we found the targte, try reducing the higher index
            // so that we approach to minimum possible index of target
            if (nums[mid] == target)
            {
                lindex = mid;
                high = mid - 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << "lower index is: " << lindex << endl;
        low = 0, high = n - 1, lindex, hindex;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // if we found the target, try increasing higher index
            // so that we approach to maximum possible index of target
            if (nums[mid] == target)
            {
                hindex = mid;
                low = mid + 1;
            }
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        cout << "higher index is: " << hindex << endl;
        op.push_back(lindex);
        op.push_back(hindex);
        return op;
    }
};