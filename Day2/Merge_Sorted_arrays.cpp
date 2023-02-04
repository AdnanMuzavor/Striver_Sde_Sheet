/*
88. Merge Sorted Array
Easy

7079

617

Add to List

Share
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.



Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.


Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109

*/
#include <bits/stdc++.h>
using namespace std;

// TC-> O((N+M)log(N+M))
// SC-> O(1)
// drawback, whats use of sorted arraye being given???
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Bruet force will be to combine both the arrays and sort the array
        int j = 0;
        // Combine elemnts of both array
        for (int i = m; i < (m + n); i++)
            nums1[i] = nums2[j++];
        // sort the resultant array
        sort(nums1.begin(), nums1.end());
    }
};

// TC-> O((N+M))
// SC-> O(N+M)
// drawback, whats use of sorted arraye being given???
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // edge case
        /// CASE01: if nums2 is empty ,nums1 is ans
        if (n == 0 && m != 0)
            nums1 = nums1; // CASE-01

        /// CASE02: if nums1 is empty then nums1=nums2 will be the answer
        if (m == 0 && n != 0)
            nums1 = nums2; // CASE-02

        /// CASE03: if non is null then follow the procedure

        if (n != 0 && m != 0)
        {
            // Since both the arrays are sorted
            // We can make use of two pointer approach
            // But will need an extra space

            vector<int> soln(n + m, 0);

            int i = 0, j = 0, k = 0;

            // Add elemnts in sorted order
            while (i < m && j < n)
            {
                if (nums1[i] <= nums2[j])
                    soln[k++] = nums1[i++];
                else
                    soln[k++] = nums2[j++];
            }
            // Add remaing elements from nums1
            while (i < m)
                soln[k++] = nums1[i++];
            // Add remaining elemnts from nums2
            while (j < n)
                soln[k++] = nums2[j++];

            i = 0;
            // Add sorted elemts to nums1
            while (i < (m + n))
            {
                nums1[i] = soln[i];
                i++;
            }
        }
    }
};

// TC-> O((N+M)(NlogN))
// At max we can have N+M traversals and at each traversal we have probability of sorting the array with N size

// SC-> O(1)
// drawback, whats use of sorted arraye being given???
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // edge case
        /// CASE01: if nums2 is empty ,nums1 is ans
        if (n == 0 && m != 0)
            nums1 = nums1; // CASE-01

        /// CASE02: if nums1 is empty then nums1=nums2 will be the answer
        if (m == 0 && n != 0)
            nums1 = nums2; // CASE-02

        /// CASE03: if non is null then follow the procedure
        if (m != 0 && n != 0)
        {
            int i = 0, j = 0;
            while (i < m && j < n)
            {
                // nums1_ele <= nums2_ele hence it deserves to be in num1
                if (nums1[i] <= nums2[j])
                    i++;
                else
                {
                    // nums1_ele > nums2_ele hence it nums2_ele deserves to be in nums1
                    swap(nums1[i], nums2[j]);
                    // And we sort nums2 array so that we follow the same trend
                    sort(nums2.begin(), nums2.end());
                }
            }
            // Now we have all smaller elements in nums1
            // and all larger elements in nums2
            // Hnece combine
            i = m, j = 0;
            while (i < (m + n))
                nums1[i++] = nums2[j++];
        }
    }
};

// TC-> O((N+M))
// SC-> O(1)
// drawback, whats use of sorted arraye being given???
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // We can come accross conclsuion that
        // we need to do reverse sorting in this array
        // example:
        /*
          nums1= 1 2 3 0 0 0
          nums2= 2 5 6

          lets i start iterating from last of nums1
          lets j start iterating from last og nums2
          lets k be pointer at last position of nums1 where we shall be adding elements

          Iteration-01
          nums1= 1 2 3 0 0 0
                     i     k
          nums2= 2 5 6
                     j
          num1[i]<=num2[j] hence swap num2[j],num1[k], j--, k--
          nums1= 1 2 3 0 0 6
                     i   k
          nums2= 2 5 6
                   j

          _________________________________________________________________________
          Iteration-02
          nums1= 1 2 3 0 0 6
                     i   k
          nums2= 2 5 6
                   j
          num1[i]<=num2[j] hence swap num2[j],num1[k], j--, k--
          nums1= 1 2 3 0 5 6
                     i k
          nums2= 2 5 6
                 j
          ___________________________________________________________________________
          Iteration-03
          nums1= 1 2 3 0 5 6
                     i k
          nums2= 2 5 6
                 j
          nums1[i]>nums2[j] hence swap nums1[i],nums1[k], i--,k--
          nums1= 1 2 0 3 5 6
                   i k
          nums2= 2 5 6
                 j
          ___________________________________________________________________________
          Iteration-04
          nums1= 1 2 0 3 5 6
                   i k
          nums2= 2 5 6
                 j
          nums1[i]<=nums2[j] swap nums2[j],nums1[k], j--,k--
          nums1= 1 2 2 3 5 6
                  i,k
          nums2= 2 5 6
                j
          _____________________________________________________________________________
           j==-1 therefore STOP

        */
        int i = m - 1, j = n - 1, k = (m + n) - 1;
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] <= nums2[j])
            {
                nums1[k] = nums2[j];
                k--;
                j--;
            }
            else
            {
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }
        // Add the remaing elements if any
        while (i >= 0)
            nums1[k--] = nums1[i--];
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};