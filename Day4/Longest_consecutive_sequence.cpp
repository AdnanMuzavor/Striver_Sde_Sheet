/*
128. Longest Consecutive Sequence
Medium

12835

531

Add to List

Share
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.



Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
Accepted
877,480
Submissions
1,789,846
*/
#include <bits/stdc++.h>
using namespace std;

// O(NlogN)
// O(1)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        // Sort the array
        sort(nums.begin(), nums.end());
        // get size
        int n = nums.size();
        // max len
        int max_len = 1, curr_len = 1; // as 1 can always be the asnwer
        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                    curr_len++;
                else
                {
                    max_len = max(max_len, curr_len);
                    curr_len = 1;
                }
            }
        }
        // fidn the ans
        // It might happen that we might not be able to upfate the answer,
        // hecne take the max
        return max(max_len, curr_len);
    }
};

// O(N)
// O(N)

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // We can have presence of each value
        // and avoid duplicates with mapping
        // Henc map each value, so that we know it's occurence
        unordered_map<int, int> mp;
        for (auto e : nums)
            mp[e] = 1;
        int n = nums.size();
        int max_len = 0;

        // Now Iterate through each element and check for subsequence
        for (int i = 0; i < n; i++)
        {

            // If this element can be first elemnt in subsequence
            // What is the sue of it, if its already part of subsequence
            // Eevn if we consider it we might get shorted length

            if (!mp[nums[i] - 1])
            {

                int first = nums[i];

                int next = nums[i] + 1;

                while (mp[next])
                    next++; // While consecutive elements are present in array

                // WWe jump her once next is not present here
                // Henc ew ehave consecutive elemnts from nums[i] i.e first till next-1
                // Hence update max_len
                max_len = max(max_len, next - first);
            }
        }

        return max_len;
    }
};