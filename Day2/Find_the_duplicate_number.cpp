/*
287. Find the Duplicate Number
Medium

15945

2052

Add to List

Share
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.



Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3


Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
*/

#include <bits/stdc++.h>
using namespace std;

// O(N)
// O(1)
// Drawback->Changes array
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // If we could modify the array
        // Then since array consist of integers from 1-n
        // Its obvious that with help of that element we would be able to visit
        // a location again for second time
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] >= 0)
            {
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
            else
            {
                return abs(nums[i]);
            }
        }
        return -1;
    }
};

// O(N)
// O(N)
// Drawback->Uses extra space
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto e : nums)
            mp[e]++;
        for (auto e : mp)
            if (e.second >= 2)
                return e.first;
        return -1;
    }
};

// O(N)
// O(1)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // We can use the concept of slow and fast pointers
        // take example
        /*
           [1,3,4,2,2]

           nums[0]=1 -> nums[1]=3 -> nums[3]=2 -> nums[2]=4 -> nums[4]
                                            ^                     |
                                            |                     |
                                            |_____________________|
           ___________________________________________________________________
           clearl view:
           ___________________________________________________________________
           1 -> 3 -> 2 -> 4
                     ^     |
                     |_____|

           Lets place slow and fast pointers(Tortoise method)
           ->Slow pointer will always move by 1place
           ->Fast pointer will always move by 2 places
           ___________________________________________________________________
            1 -> 3 -> 2 -> 4
           s,f       ^     |
                     |_____|

            moved s by 1 and f by 2
           _______________________________________________________________
                1 -> 3 -> 2 -> 4
                     s   ^f    |
                         |_____|

            moved s by 1 and f by 2

            _______________________________________________________________
              1 -> 3 -> 2 -> 4
                      s,f    |
                       |_____|

            moved s by 1 and f by 2
            f after moving 2 steps comes back to 2 and slow comes at [2]
            ______________________________________________________________
            KEEP s AT SAME PLACE AND MOVE F TO FRONT

               1 -> 3 -> 2 -> 4
               f        s     |
                        |_____|
            ______________________________________________________________
            UNTIL THEY MEET, MOVE BOTH OF THEM BY ONE STEP
            ______________________________________________________________
              1 -> 3 -> 2 -> 4
                   f    |    s|
                        |_____|
            Moved f and s by one step
            ______________________________________________________________
               1 -> 3 -> 2 -> 4
                        |s,f  |
                        |_____|
            s==f hence stop
            ______________________________________________________________
            HENCE REEATED ELEMENT IS 2 WHER ETHEY MEET

                          */

        // we dont have to make any linked list here
        // elements themselves will direct us

        // 1)Keep slow and fast at first element
        int slow = nums[0], fast = nums[0];

        // 2)Move slow and fast until they become equal
        do
        {
            slow = nums[slow]; // Moved slow by one
            fast = nums[fast]; // Moved fast by one
            fast = nums[fast]; // Moved fast by two
        } while (nums[slow] != nums[fast]);

        // 3)As slow and fast meet,place fast back at first pos
        fast = nums[0];

        // 4)Move slow and fast until they meet
        while (slow != fast)
        {

            slow = nums[slow];
            fast = nums[fast];
        }

        // 5)The point they meet is the answer
        return slow;
    }
};