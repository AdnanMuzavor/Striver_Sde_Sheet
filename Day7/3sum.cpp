/*
15. 3Sum
Medium

21971

2015

Add to List

Share
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> op; // To keep the o/p
        vector<int> temp;       // To store elemnts temporarily
        int n = nums.size();
        // Brute force
        // use three loop
        // draw back: 1) O(N^3)
        //            2) duplicate pairs

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int new_target = 0 - nums[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int new_sum = nums[j] + nums[k];
                if (new_sum == new_target)
                {
                    // Add elemnts into temp
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    // push temp in op
                    op.push_back(temp);
                    // clear temp for next combo
                    temp.clear();
                    // Now it may happen that same elelemnt as nums[j]
                    // repeat for futher iteration and for same k(unchanged)
                    // and changed updated j we might have same ans
                    // hence it's necessary to move j and k so as to
                    // remove duplicates
                    int x = nums[j], y = nums[k];
                    while (j < k && nums[j] == x)
                        j++;
                    while (k > j && nums[k] == y)
                        k--;
                }
                else if (new_sum > new_target)
                    k--;
                else
                    j++;
            }
            // Now case for j and k repeatation handled
            // same can heappen for i as well
            // hence updates for i
            int val = nums[i];
            while (i + 1 < n && nums[i] == nums[i + 1]) // and 1 increment will be done by loop
                i++;
        }
        return op;
    }
};