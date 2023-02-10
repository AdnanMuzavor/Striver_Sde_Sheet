/*
46. Permutations
Medium

13446

225

Add to List

Share
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]


Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(int index, int n, vector<int> nums, vector<vector<int>> &op)
    {
        if (index == n)
        {
            op.push_back(nums);
            return;
        }
        for (int i = index; i < n; i++)
        {
            swap(nums[i], nums[index]);
            helper(index + 1, n, nums, op);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> op;
        int n = nums.size();
        helper(0, n, nums, op);
        return op;
    }
};