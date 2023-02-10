/*
90. Subsets II
Medium

6817

192

Add to List

Share
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
Accepted
614,070
Submissions
1,112,398
*/

#include <bits/stdc++.h>
using namespace std;

//Uses set to maintain unique pairs, so less efficient and needs extra space
class Solution
{
public:
    set<vector<int>> op;
    void helper(vector<int> curr, int index, vector<int> nums)
    {
        if (index == nums.size())
        {
            sort(curr.begin(), curr.end());
            op.insert(curr);
            return;
        }
        // Take
        curr.push_back(nums[index]);
        helper(curr, index + 1, nums);
        // Not take
        curr.pop_back();
        helper(curr, index + 1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> curr;
        helper(curr, 0, nums);
        vector<vector<int>> soln;
        for (auto e : op)
        {
            soln.push_back(e);
        }
        return soln;
    }
};

//Uniqyes are taken care using the sorting
class Solution
{
public:
    void helper(vector<vector<int>> &op, vector<int> curr, vector<int> nums, int index)
    {
        op.push_back(curr);
        for (int i = index; i < nums.size(); i++)
        {
            if (i != index && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            helper(op, curr, nums, i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> op;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(op, curr, nums, 0);
        return op;
    }
};