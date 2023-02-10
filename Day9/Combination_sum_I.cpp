/*
39. Combination Sum
Medium

13841

280

Add to List

Share
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.



Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []


Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/
#include <bits/stdc++.h>
using namespace std;

// Being new, this is the only approahc that 'll come to your mind
class Solution
{
public:
    void helper(set<vector<int>> &op, vector<int> curr, int sum, int target, int index, vector<int> nums)
    {
        /// cout<<"sum: "<<sum<<"target: "<<target<<endl;
        if (sum > target)
            return;
        if (sum == target)
        {
            op.insert(curr);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            helper(op, curr, sum, target, i + 1, nums); // try next element
            curr.push_back(nums[i]);
            helper(op, curr, sum + nums[i], target, i, nums);     /// Tske same element again
            helper(op, curr, sum + nums[i], target, i + 1, nums); // try next element
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        set<vector<int>> op;
        vector<vector<int>> op1;
        vector<int> curr;
        helper(op, curr, 0, target, 0, nums);
        for (auto e : op)
            op1.push_back(e);
        return op1;
    }
};

class Solution
{
public:
    void helper(vector<vector<int>> &op, vector<int> curr, int target, vector<int> nums, int index)
    {
        if (!target)
        {
            op.push_back(curr);
            return;
        }
        for (int i = index; i < nums.size() && nums[i] <= target; i++)
        {
            curr.push_back(nums[i]);
            helper(op, curr, target - nums[i], nums, i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> op;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(op, curr, target, nums, 0);
        return op;
    }
};