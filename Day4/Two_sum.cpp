/*
1. Two Sum
Easy

36866

1176

Add to List

Share
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.



Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.


Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/

#include <bits/stdc++.h>
using namespace std;

// BRUET FORCE APPROACH  [CODE FOR UNIQUE AND NOT UNIQUE]
// TC -> O(N^2)
// SC -> O(N)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> op;

        vector<int> used(n, 0); // To keep track which indices were used

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                // If indices were not used and target is achieved
                if (!used[i] && !used[j] && nums[i] + nums[j] == target)
                {
                    used[i] = 1;
                    used[j] = 1;
                    op.push_back(i);
                    op.push_back(j);
                    // j will be incrrementing in next iteration
                    // so just increment i
                    i++;
                }
            }
        }
        return op;
    }
};

// Optimised [CODE FOR UNIQUE AND NOT UNIQUE] WORST CASE  MAP TAKES O(N) time hence can become O(n^2)
// TC -> O(N)
// SC -> O(N)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        vector<int> op;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            int find_num = target - nums[i]; // Means i th inde xis current index
            if (mp.find(find_num) != mp.end())
            {
                // means other pair is present in array
                // Hence push it into the array

                op.push_back(mp[find_num]); // index of element we are looking for

                op.push_back(i); // index of element we process now

                mp[find_num] = 0; // deduct the presence of element
                                  // so that it's not considered next time

                continue; // since curr nums[i] is used, we need not
                          // use it again hence avoid mapping
            }
            mp[nums[i]] = i; // map value with index
        }
        return op;
    }
};