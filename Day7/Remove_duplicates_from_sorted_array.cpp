/*
26. Remove Duplicates from Sorted Array
Easy

8454

12130

Add to List

Share
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.



Example 1:

Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


Constraints:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums is sorted in non-decreasing order.
Accepted
2,491,611
Submissions
4,960,563
*/

#include <bits/stdc++.h>
using namespace std;
//O(N)+O(1)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int c = 0, n = nums.size(), index = 1; // index ofr modified array
        int rep = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == rep)
                c++; // Increase in blank slot as this no
                     // is repeated an dhave to be deleted
            else
            {
                // new rep number we found is nums[i] as it's not equal to rep
                rep = nums[i];
                nums[index] = rep;
                index++;
            }
        }
        // index untill where we have proper non repeating elemnts
        return n - c;
    }
};