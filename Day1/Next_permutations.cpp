/*
31. Next Permutation
Medium

12434

3701

Add to List

Share
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.



Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]


Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 100
*/

#include <bits/stdc++.h>
using namespace std;

// TC-> O(N!*N+N!) each of the N elements can be placed in N! ways
//      +N! is to traverse the array cpontaing N! permutations and find next permutation
//      [1,2,3]
//       i
//      1 can be placed at 3 ways,2 can be placed in 2 ways and 1 can be placed in 1 way
//      =>3*2*1=3!

//     [2,1,3]
//        i
//     2 can be placed at 3 ways,1 can be placed in 2 ways and 3 can be placed in 1 way
//     =>3*2*1=3!

//     [3,2,1]
//          i
//     3 can be placed at 3 ways,2 can be placed in 2 ways and 1 can be placed in 1 way
//     =>3*2*1=3!

// This can be done at 3 times
// Hence 3*3!  => N*N! => O(N*N!)

// SC-> O(N!) to store all factorials of N
class Solution
{
public:
    vector<vector<int>> op;
    void permute(int start, vector<int> nums)
    {
        if (start >= nums.size())
        {
            op.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            permute(start + 1, nums);
            swap(nums[i], nums[start]);
        }
    }

    void nextPermutation(vector<int> &nums)
    {
        // Brute force
        // Just find all permutations, return next permutation

        // Preserve the nums
        vector<int> num1;
        num1 = nums;

        // Find all permutation of nums
        permute(0, nums);

        // Sort permutations as we nee dthem to be in lexographically incresing order
        sort(op.begin(), op.end());

        // Now for each permutattion..
        for (int i = 0; i < op.size(); i++)
        {

            int ans;
            // If a permutation is at ith element
            if (op[i] == num1)
            {

                // it's ans is in i+1 th element
                ans = i + 1;

                // If given permutaion is at alst,
                // it's next permutation will be first permutation
                if (ans == op.size())
                    ans = 0;

                // then as per k , we copy value in nums//UPDATE nums
                int k = 0;
                for (auto e : op[ans])
                    nums[k++] = e;
            }
        }
    }
};

// TC-> O(N) => O(N+N+N)
//           => N for finding breakpoint (inde d)
//           => N for finding value > arr[d]
//           => N for reversing

// SC-> O(1) to store only vars
class Solution
{
public:
    vector<vector<int>> op;
    void permute(int start, vector<int> nums)
    {
        if (start >= nums.size())
        {
            op.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            swap(nums[start], nums[i]);
            permute(start + 1, nums);
            swap(nums[i], nums[start]);
        }
    }

    void nextPermutation(vector<int> &nums)
    {
        // Algorithm
        // 1)Traverse from back of an array
        ///->Find first i such that a[i]<a[i+1]
        ///->Say it's index d
        ///-> 1 3 5 4 2
        /// d=01 (value=3)

        // 2)Traverse from back of array
        ///->Find first element with value>a[d]
        ///->Say value is at d2
        ///-> 1 3 5 4 2
        ///->value 4, d2=03

        // 3)Swap valeus at index d and d2
        ///->swap(arr[d],arr[d2])
        ///->before:  1 3 5 4 2
        ///->after:   1 4 5 3 2

        // 4)Reverse everything from d+1 to last index
        ///->before:  1 4 5 3 2
        ///->after:   1 4 2 3 5
        /// THIS IS NEXT PERMUTATION

        // INTUITION:
        /*          /\
              5      \
            3   4     \    Value is incrreasing from back to certain value i.e increasing
          1       2    \   sequence

          EVEN INCASE OF 1 2 3 :
               3
             2             We can say that [3] itself is an increasing sequence
           1
        */

        /*
             5
           \   4         Hence we can say that point after 1,3 is break point
          3      2       Hence we need a value to make tbis prefix greater
       1                 Hence in step 3 to make the prefix greater
                         we replace it with 4, while the order on RHS is still increasing
                         like before

                   /\
             5      \
           4   3     \    Value is incrreasing from back to certain value i.e increasing
         1       2    \   sequence AFTER SWAPPING

         //Now to get next permutation,we have just [5,3,2] on left hand side
         //to get NEXT PERMUTATION we need to make the permutation as lesser in rank as                 //possible
         //this is done by sorting i.e reversing in increasing order

         //EDGE CASE:

         5
           4
             3         This case i will reach to -1
               2       means next permutation can just be fround by reversing
                 1


         */

        // STEP-1: Find first element lesser then i+1th element
        // This is where we are finding the breakpoint
        int n = nums.size(), i, d, d1;
        for (i = n - 2; i >= 0; i--)
        {

            if (nums[i] < nums[i + 1])
            {
                d = i;
                break;
            }
        }

        // Taking care of edge case
        if (i == -1)
            reverse(nums.begin(), nums.end());

        else
        {
            // STEP-2: Find first element with value > value[d]
            for (int i = n - 1; i >= 0; i--)
            {
                if (nums[i] > nums[d])
                {
                    d1 = i;
                    break;
                }
            }

            // Step-3: Swap values at d and d1
            swap(nums[d], nums[d1]);

            // Step-4: Revsere the array from d+1th index to last
            reverse(nums.begin() + d + 1, nums.end());
        }
    }
};