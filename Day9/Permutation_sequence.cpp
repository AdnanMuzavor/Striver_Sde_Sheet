/*
60. Permutation Sequence
Hard

4922

423

Add to List

Share
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.



Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"


Constraints:

1 <= n <= 9
1 <= k <= n!
Accepted
302,783
Submissions
692,738
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // O(K*N) => K time sfind the next permutation where finding next perm takes N time
    // Fid next permutayion
    void nextperm(vector<int> &nums)
    {
        int di = -1;
        // find id ther ei is elemnt such that nums[i]<nums[i+1]
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                di = i;
                break;
            }
        }
        if (di == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        else
        {
            // Find first elemnt gretar thn elemnt at di and swap
            for (int i = nums.size() - 1; i >= di; i--)
            {
                if (nums[i] > nums[di])
                {
                    int temp = nums[di];
                    nums[di] = nums[i];
                    nums[i] = temp;
                    break;
                }
            }

            // reverse array from di+1 till end
            reverse(nums.begin() + di + 1, nums.end());
        }
    }
    string getPermutation(int n, int k)
    {
        vector<int> nums(n);
        for (int i = 1; i <= n; i++)
        {
            nums[i - 1] = i;
        }
        // Fidn next permutatyion of this nums array
        // at k-1 times
        while (--k)
        {
            nextperm(nums);
        }
        string res = "";
        for (auto e : nums)
            res += to_string(e);
        return res;
    }
};