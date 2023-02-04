/*
315. Count of Smaller Numbers After Self
Hard

7380

200

Add to List

Share
Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].



Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:

Input: nums = [-1]
Output: [0]
Example 3:

Input: nums = [-1,-1]
Output: [0,0]


Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/
#include <bits/stdc++.h>
using namespace std;
// O(N^2)+O(1)
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        // Brute force
        vector<int> op;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] < nums[i])
                    count++;
            }
            op.push_back(count);
        }
        return op;
    }
};

// O(NLOGN)
// O(2N)
class Solution
{
public:
    // Lets use the concept of merge sort
    void merge(vector<pair<int, int>> &nums, vector<int> &op, int l, int m, int h)
    {

        // Fidn count of smaller elements
        int i = l, j = m + 1, k = 0;
        for (int i = l; i <= m; i++)
        {
            while (j <= h && nums[j].first < nums[i].first)
                j++;
            op[nums[i].second] = op[nums[i].second] + (j - (m + 1));
        }

        // Merge the array
        vector<pair<int, int>> temp(h - l + 1);
        i = l, j = m + 1, k = 0;
        while (i <= m && j <= h)
        {
            if (nums[i].first <= nums[j].first)
            {

                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }

        while (i <= m)
            temp[k++] = nums[i++];
        while (j <= h)
            temp[k++] = nums[j++];

        k = 0;
        for (int i = l; i <= h; i++)
            nums[i] = temp[k++];
    }
    void mergesort(vector<int> &op, vector<pair<int, int>> &nums, int l, int h)
    {
        if (l < h)
        {
            int m = (l + h) / 2;
            mergesort(op, nums, l, m);
            mergesort(op, nums, m + 1, h);
            merge(nums, op, l, m, h);
        }
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();

        // Copy nums into op1, to prevent the order
        // Eelments will be sorted but their indexes will be safe
        // Hence we'll be able to put count value at indices
        vector<pair<int, int>> dup(n);
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            dup[i] = p;
        }

        // declare output which will all all values
        vector<int> output(n, 0);

        // call merge sort
        mergesort(output, dup, 0, n - 1);

        return output;
    }
};