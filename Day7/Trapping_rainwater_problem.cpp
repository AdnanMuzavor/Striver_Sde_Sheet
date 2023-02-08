/*
Trapping Rain Water
Medium Accuracy: 49.62% Submissions: 100k+ Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.
Given an array arr[] of N non-negative integers representing the height of blocks. If width of each block is 1, compute how much water can be trapped between the blocks during the rainy season.


Example 1:

Input:
N = 6
arr[] = {3,0,0,2,0,4}
Output:
10
Explanation:

Example 2:

Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above
block of height 4 is 3 units and above
block of height 0 is 7 units. So, the
total unit of water trapped is 10 units.
Example 3:

Input:
N = 3
arr[] = {6,9,9}
Output:
0
Explanation:
No water will be trapped.

Your Task:
You don't need to read input or print anything. The task is to complete the function trappingWater() which takes arr[] and N as input parameters and returns the total amount of water that can be trapped.


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here
        // To accumulate water
        // We know that there will be column on left side to prevcent left flow
        // There will also be column at right side to prevent right side flow
        // Now how much water can be accumulated between these two columns

        // WHICH HEIGHT TO CONSIDER AND WHY?
        // CASE-1: Assume that left column height> right column height
        //       =>Water will definetely flow doen from right column side
        //     | -----
        //     | |   |
        //     | |    -- Flow out
        //     | |
        // Hence its obvious that among heeight of left and right colums
        // We should select minimum height column to accumulate the water

        // CASE02 :Now that columns afre selected there are chances that
        // current ith index for whom we have chosen minimum amomg left and right
        // it self has column so area corresponding that height of column
        // should be subtracted
        //    | -----
        //    | |   |
        //    |_|    -- Flow out
        //    |E|-->Exclude this area

        // Hence units of water accumulated =2

        // SO WHAT DOES FORMULA BECOMES
        // ans=ans+min(right,left)-arr[i] //i.e height of current index column

        // Lets take up an example
        // given array
        //               3         0         0        2        0         4
        // Left columns  3         3         3        3        3         4
        // right columns 4         4         4        4        4         4
        // ans=         min(3,4)  min(3,4) min(3,4) min(3,4) min(3,4) min(4,4)
        //              3         3        3        3        3        4
        //              3-arr[i]  3-arr[i] 3-arr[i] 3-arr[i] 3-arr[i] 4-arr[i]
        //              3-3       3-0      3-0      3-2      3-0      4-4
        //              0 units   3 units  3 units  1 units  3 units  0 units
        // Hence answer= 3+3+1+3=10

        // We need left array which will store maximum height fromm left
        long long left[n];
        // Lets initialise it
        left[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max((long long)arr[i], left[i - 1]);
        }

        // We need right array which will store maximum height fromm right
        long long right[n];
        // Lets initialise it
        right[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max((long long)arr[i], right[i + 1]);
        }

        // Now lets get the answer
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans + (min(left[i], right[i]) - (long long)arr[i]);
        }

        return ans;
    }
};
