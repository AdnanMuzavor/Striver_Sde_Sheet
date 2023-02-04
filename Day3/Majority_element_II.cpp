/*
229. Majority Element II
Medium

5781

302

Add to List

Share
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109


Follow up: Could you solve the problem in linear time and in O(1) space?

Accepted
330,949
Submissions
760,746
*/

#include <bits/stdc++.h>
using namespace std;

// BRUTE FORCE
//  TC -> O(N^2)
//  SC -> O(1)

// TC -> O(N)
// SC -> O(N)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // METHOD-I
        vector<int> op;
        int n = nums.size();
        unordered_map<int, int> m;
        for (auto e : nums)
            m[e]++;
        for (auto e : m)
        {
            if (e.second > (n / 3))
                op.push_back(e.first);
        }
        return op;
    }
};

// TC -> O(NlogN)
// SC -> O(1)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> op;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int element = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            // count fpr current element
            if (count == 0)
                element = nums[i];

            // keep counting current element
            if (nums[i] == element)
                count++;

            // If finishded counting current elemnt then count next element
            if (nums[i] != element)
            {
                if (count > (n / 3))
                    op.push_back(element);
                element = 0;
                count = 0;
                i--; // To count current element i.e nums[i]
            }
        }
        // If any elemnt was missed
        if (count > (n / 3))
            op.push_back(element);
        return op;
    }
};

// O(N+N)
// O(1)

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // In case of greater then n/2 problem we knew that if an element is
        // occuring greater then n/2 times then it's obvious ther ewill be only one
        // majority element

        // Similarly incase of n/3 eleemnts if an element is occuring > n/3 times, its obvious           //there will be <=2 majority elements

        // Hence we can use the same moore voting algorithm, thisn time for two elemnts
        int ele1 = -1, ele2 = -1, c1 = 0, c2 = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (ele1 == nums[i])
                c1++;
            else if (ele2 == nums[i])
                c2++;
            else if (c1 == 0)
            {
                ele1 = nums[i];
                c1 = 1;
            }
            else if (c2 == 0)
            {
                ele2 = nums[i];
                c2 = 1;
            }

            else
            {
                c1--;
                c2--;
            }
        }

        // Here its not sured that array will have majority element, hence we should verify
        int c_1 = 0, c_2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == ele1)
                c_1++;
            if (nums[i] == ele2)
                c_2++;
        }
        // Add into op only after verification
        vector<int> op;
        if (c_1 > (n / 3))
            op.push_back(ele1);
        if (c_2 > (n / 3) && ele1 != ele2)
            op.push_back(ele2);

        // return the answer
        return op;
    }
};