/*
493. Reverse Pairs
Hard

3748

199

Add to List

Share
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].



Example 1:

Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 5 > 2 * 1


Constraints:

1 <= nums.length <= 5 * 104
-231 <= nums[i] <= 231 - 1
Accepted
100,414
Submissions
327,487
*/

#include <bits/stdc++.h>
using namespace std;

// RUN TIME ERROR
// Brute force
// O(n^2)
// O(1)

class Solution
{
public:
  int reversePairs(vector<int> &nums)
  {
    int n = nums.size(), count = 0;
    for (int i = 0; i < n - 1; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        if (nums[i] > (2 * nums[j]))
          count++;
      }
    }
    return count;
  }
};

// O(NlogN)
// O(1)

class Solution
{
public:
  int merge(vector<int> &nums, int l, int m, int h)
  {
    int i = 0, j = m + 1, k = 0;

    int count = 0;

    int temp[h - l + 1];
    for (int i = l; i <= m; i++)
    {
      //-> While condition is satisfied wrt j for current i
      //-> keep moving j
      //-> even if j reaches h
      //-> for next i,which will obviously satisfy condition as prev_i
      //-> made j reach to h and completed the array
      // -> hence j wont move any further but we can definitely add the count

      while (j <= h && (nums[i] > 2ll * nums[j]))
        j++;
      count += (j - (m + 1));
    }
    // MERGE PART
    i = l, j = m + 1, k = 0;
    while (i <= m && j <= h)
    {
      if (nums[i] <= nums[j])
        temp[k++] = nums[i++];
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

    return count;
  }
  int mergesort(vector<int> &nums, int l, int h)
  {
    int count = 0;
    if (l < h)
    {
      int mid = (l + h) / 2;
      count += mergesort(nums, l, mid);
      count += mergesort(nums, mid + 1, h);
      count += merge(nums, l, mid, h);
    }
    return count;
  }
  int reversePairs(vector<int> &nums)
  {
    int ans = mergesort(nums, 0, nums.size() - 1);
    return ans;
    // We can apply modified ,erge sort algo as well
    /*
                      40 25 19 12 9 6 2
                        /           \
                       /             \
                  40 25 19 12       9 6 2
                  /     \            /  \
                 /       \          /    \
               40 25  19 12        9 6    2
               /\     /\           /\     \
              /  \   /  \         /  \     \
             40  25 19   12       9   6    2
         __________________________________________________________________________
             Procedure
             1)When nums[i]>2*nums[j] is TRUE
             =>We know we are suppose to find nums[i]>2*nums[j]
             =>That means if for condition that nums[i]<=2*nums[j]
             =>we keep on moving i as array is sorted, higher value of i
             =>will definitely fail nums[i]<=2*nums[j] making nums[i]>2*nums[j]

             2)When nums[i]>2*nums[j] is FALSE
             =>if nums[i]<=2*nums[j] is not fullfilled,it means
             =>nums[i]>2*nums[j]  is satisfied for i and j
             =>Here we would like to move j,
             =>Each movemment of j will be counted
             =>i.e if j move by one then previous element to jth index
               satisfies above condition i.e one element
             =>i.e if j move by two then previous elements to jth index
               satisfies above condition i.e two elements
        ___________________________________________________________________________
                        40 25 19 12 9 6 2
                        /           \
                       /             \
                  40 25 19 12       9 6 2
                  /     \            /  \
                 /       \          /    \
               40 25  19 12        9 6    2
               /\     /\           /\     \
              /  \   /  \         /  \     \
             40  25 19   12       9   6    2
             _______________________________________________________________________
             40 25
             i  j
             40<=2*25  => 40<=50 =>Hence probably higher value of i we need i++
             40  25
               i j     =>i outof bound hence stop and MERGE

             count=count+(movements of j) => count+0 => 0
             ________________________________________________________________________
                      40 25 19 12 9 6 2
                        /           \
                       /             \
                  40 25 19 12       9 6 2
                  /     \            /  \
                 /       \          /    \
               40 25  19 12        9 6    2
               /\     /\           /\     \
              /  \   /  \         /  \     \
             40  25 19   12       9   6    2
             \   /
              \ /
            [25,40]

             _______________________________________________________________________
             19 12
             i  j
             19<=2*12  => 19<=24 =>Hence probably higher value of i we need i++
             19  12
               i j     =>i outof bound hence stop and MERGE
             count=count+(movements of j) => count+0 => 0
            ________________________________________________________________________
                      40 25 19 12 9 6 2
                        /           \
                       /             \
                  40 25 19 12       9 6 2
                  /     \            /  \
                 /       \          /    \
               40 25  19 12        9 6    2
               /\     /\           /\     \
              /  \   /  \         /  \     \
             40  25 19   12       9   6    2
             \   /  \    /
              \ /    \  /
            [25,40]  [12,19]
            _______________________________________________________________________
             [25 40][12,19]
              i      j
             25<=2*12  => 25<=24 => FALSE => Hence current pair(i,j) contributes, move j++

             count= count +(j_movement) => 0 + 1 => 1
             ______________________________________________________________________
             [25 40][12,19]
               i         j
             25<=2*19 => 25<=38 => TRUE hence we need higher value of i, i++
             ______________________________________________________________________
             [25 40][12,19]
                  i      j
             40<=2*19 => 40<=38 => FALSE => Hence current pair(i,j) contributes, move j++

              count=count+(movements of j) => 1+2 => 3
             ________________________________________________________________________
             [25 40][12,19]
                  i        j
             i++
             => i out of bound hence STOP and MERGE
            ________________________________________________________________________
                      40 25 19 12 9 6 2
                        /           \
                       /             \
                  40 25 19 12       9 6 2
                  /     \            /  \
                 /       \          /    \
               40 25  19 12        9 6    2
               /\     /\           /\     \
              /  \   /  \         /  \     \
             40  25 19   12       9   6    2
             \   /  \    /
              \ /    \  /
            [25,40]  [12,19]
             \           /
              \         /
             [12,19,25,40]
            _______________________________________________________________________                         9  6
             i  j
             9<=2*6 => 9<=12 => Hence we need to move i to greater element i++
             9  6
               i j  i out of bound hence STOP and MERGE
             count=count+(movements of j) => 3+0 => 3
             _______________________________________________________________________
                      40 25 19 12 9 6 2
                        /           \
                       /             \
                  40 25 19 12       9 6 2
                  /     \            /  \
                 /       \          /    \
               40 25  19 12        9 6    2
               /\     /\           /\     \
              /  \   /  \         /  \     \
             40  25 19   12       9   6    2
             \   /  \    /        \  /     |
              \ /    \  /          \/      |
            [25,40]  [12,19]     [6,9]     2
             \           /
              \         /
             [12,19,25,40]
            ____________________________________________________________________
             [6,9]  [2]
              i      j
              6<=2*2 => 6<=4 FALSE Hence current (i,j) contrinutes to count j++

              count=count+1  => 3+1 => 4
              _________________________________________________________________
             [6,9]  [2]
              i        j
             STOP
             [6,9]  [2]
                i       j
             i<=mid since arr[i]=6 contributes to count, all remaining elemnts
             bring greater will also contribute to count
             count= count+(movement_j_for each_i)
                  =  5   + 1
                  =  6
             ____________________________________________________________________
                       40 25 19 12 9 6 2
                        /           \
                       /             \
                  40 25 19 12       9 6 2
                  /     \            /  \
                 /       \          /    \
               40 25  19 12        9 6    2
               /\     /\           /\     \
              /  \   /  \         /  \     \
             40  25 19   12       9   6    2
             \   /  \    /        \  /     |
              \ /    \  /          \/      |
            [25,40]  [12,19]     [6,9]     2
             \           /        \       /
              \         /          \     /
             [12,19,25,40]         [2,6,9]
             ______________________________________________________________________
              [12,19,25,40]  [2,6,9]
               i              j
               12<=2*2 => 12<=4 FALSE hecce pair(i,j) contributes to count j++
               count= 6+(movement_of_j)
                    = 6+1
                    = 7
              ____________________________________________________________________
              [12,19,25,40]  [2,6,9]
               i                j
               12<=12 hence i++
              ____________________________________________________________________
              [12,19,25,40]  [2,6,9]
                  i             j
               19<=12 FALSE hecce pair(i,j) contributes to count j++
               count= 7+(move_menyt_of_j)
                    = 7+1
                    = 8
              _________________________________________________________________
               [12,19,25,40]  [2,6,9]
                    i               j
               19<=18 FALSE hecce pair(i,j) contributes to count j++
                count= 8+(move_menyt_of_j)
                    =  8+1
                    =  9
              __________________________________________________________________
              add 3 movements of j for each element >19
              __________________________________________________________________
              for 25 count= count + (j_movements corresponding to 25)
                          =   9   + 3
                          =   12
              __________________________________________________________________
              for 40 count= count + (j_movements corresponding to 40)
                          =   12   + 3
                          =   15

    */

    return 0;
  }
};