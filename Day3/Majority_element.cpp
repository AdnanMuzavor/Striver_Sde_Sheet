/*
169. Majority Element
Easy

11488

374

Add to List

Share
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2


Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

#include <bits/stdc++.h>
using namespace std;

// Brute force
// - > O(n^2)
// - > O(1)

// TC - > O(N)
// SC - > O(N)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        // Map all the elements
        for (auto e : nums)
        {
            m[e]++;
        }

        // Find which element occures > = (n/2) times
        for (auto e : m)
        {

            if (e.second >= (n / 2) + 1)
                return e.first;
        }
        return -1;
    }
};

// TC-> O(N)
// SC-> O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // MOOSE VOTING ALGORITHM
        /*
        Consider:

        =>INITIALISATION
        count=0
        element=0

        =>ITERATION
        7 7 5 7 5 1 5 7 5 5 7 7 5 5 5 5
        i

        arr[i]=7 and count=0 hence update ele and count++   | element=7 | count=1 | i++
       arr[i]=7 and count!=0 & ele=7hence increment count   | element=7 | count=2 | i++
       arr[i]=5 and count!=0 & ele=7hence decrement count   | element=7 | count=1 | i++
       arr[i]=7 and count!=0 & ele=7hence increment count   | element=7 | count=2 | i++
       arr[i]=5 and count!=0 & ele=7hence decrement count   | element=7 | count=1 | i++
       arr[i]=1 and count!=0 & ele=7hence decrement count   | element=7 | count=0 | i++
       _________________________________________________________________________________

       7 7 5 7 5 1| 5 7 5 5 7 7 5 5 5 5
       __________________________________________________________________________________
       arr[i]=5 and count==0 hence update ele and count++   | element=5 | count=1 | i++
       arr[i]=7 and count!=0 & ele=5hence decrement count   | element=5 | count=0 | i++
       _________________________________________________________________________________

       7 7 5 7 5 1| 5 7| 5 5 7 7 5 5 5 5
       _________________________________________________________________________________
       arr[i]=5 and count==0 hence update ele and count++   | element=5 | count=1 | i++
       arr[i]=5 and count!=0 & ele=5hence increment count   | element=5 | count=2 | i++
       arr[i]=7 and count!=0 & ele=5hence decrement count   | element=5 | count=1 | i++
       arr[i]=7 and count!=0 & ele=5hence decrement count   | element=5 | count=0 | i++
       _________________________________________________________________________________

       7 7 5 7 5 1| 5 7| 5 5 7 7|5 5 5 5
       _________________________________________________________________________________
       arr[i]=5 and count==0 hence update ele and count++   | element=5 | count=1 | i++
       arr[i]=5 and count!=0 & ele=5hence increment count   | element=5 | count=2 | i++
       arr[i]=5 and count!=0 & ele=5hence increment count   | element=5 | count=3 | i++
       arr[i]=5 and count!=0 & ele=5hence increment count   | element=5 | count=4 | i++

       AS PER ALGORITHM ,ELEMENT IN element variable is MAJORITY ELEMENT

       //Lets understand the intuition:
       _________________________________________________________________________________

       7 7 5 7 5 1| 5 7| 5 5 7 7|5 5 5 5
       _________________________________________________________________________________

       =>we know that majority element always exists and that element will always appear
       >[n/2] times

       =>Hence her majority_count != minority_count

       =>Hence at last the count of the element whose value is not rediuce dto zero
       by minority count is the answer

       =>i.e if we incrememnt count for an element considering it as majority
        and we decrement count for anothe relement considering it as minority
        then even after each decrement of count, count!=0 for majority element
        as it appears greter then n/2 times

        //Lets udnertsand this
        _________________________________________________________________________________

        7 7 5 7 5 1| 5 7| 5 5 7 7|5 5 5 5
        _________________________________________________________________________________
        consider first prefix where count was reduced to zero
        7 7 5 7 5 1
        count_7= 3
        count_5= 2
        count_1= 1
        Hence clearly if we considerd 7 as majority, other minority elements are reducing             count to zero
        _________________________________________________________________________________
        consider second prefix where count was reduced to zero
        5 7
        count_5= 1
        count_7= 1
        Hence clearly if we considerd 5 as majority, other minority elements are reducing             count to zero
        _________________________________________________________________________________
        consider third prefix where count was reduced to zero
        5 5 7 7
        count_5= 2
        count_7= 2
        Hence clearly if we considerd 5 as majority, other minority elements are reducing             count to zero
        _________________________________________________________________________________
        consider third prefix where count was reduced to zero
        5 5 5 5
        count_5= 4
        count_minority=0
        Hence clearly if we considerd 5 as majority, no other minority elements are reducing           count to zero
        ________________________________________________________________________________
        Hence we can conclude that since 5 is elemnt whose counnt count be reduced to zero by         minority elements, it implie sthat count_5 uis greater then n/2 hence minority count           could not reduced it to zero at all
        */

        //______Moose Voting Algorithm__________

        int count = 0, element = 0; // Initialisation

        // Iteration
        for (int i = 0; i < nums.size(); i++)
        {
            if (count == 0)
                element = nums[i];
            if (nums[i] == element)
                count++;
            else
                count--;
        }

        // answer
        return element;
    }
};