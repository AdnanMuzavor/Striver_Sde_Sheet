/*
540. Single Element in a Sorted Array
Medium
6.5K
116
Companies
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.



Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
Accepted
344K
Submissions
588.2K
Acceptance Rate
58.5%
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        // Only one  elemnt, so it itself will be a single element
        if (n == 1)
            return nums[0];
        // Check for any of the middle elements
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
            i++;
        }
        // check for last elemnent
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];
        return -1;
    }
};

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // After xoring only single number will be left
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // Strivers binary solution
        int low = 0, high = nums.size() - 2, mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            // Check if it's right half,
            // if so mid should be pointing to instance
            // and first instance should be at left
            if (nums[mid] == nums[mid ^ 1])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return nums[low];
    }
};