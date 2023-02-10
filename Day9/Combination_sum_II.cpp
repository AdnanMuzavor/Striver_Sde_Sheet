/*
40. Combination Sum II
Medium

7122

174

Add to List

Share
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.



Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]


Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive function permute
    void permute(vector<vector<int>> &op, vector<int> curr, vector<int> &nums, int start, int target)
    {
        // If target zero means we found all elemets which sum up to target
        if (target == 0)
        {
            op.push_back(curr);
            return;
        }
        // Sterting from given satrting index as it'll help in preventomg multiple calls
        for (int i = start; i < nums.size() && nums[i] <= target; i++)
        {
            ///Avoid repeated numbers
            if (i != start && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            // since nums[i] included target becomes target-nums[i]
            permute(op, curr, nums, i + 1, target - nums[i]);
            // i+1 one is passed because i is considered and we cannot take up duplicates
            curr.pop_back();
            // popping back to try next combo if current does'nt works
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &nums, int target)
    {
        // Sorting array so that we can get the numbers in order
        sort(nums.begin(), nums.end());
        vector<vector<int>> op;
        // Vcetor to be used temporarily
        vector<int> curr;
        // Recursive fn
        // It'll take
        //->final output op
        //->temp array i.e curr
        //->index from where in shouyld start
        //->target i.e curr target i.e target after taking a element
        //->nums array
        permute(op, curr, nums, 0, target);
        return op;
    }
};