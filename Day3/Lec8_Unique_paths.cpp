/*
62. Unique Paths
Medium

11312

338

Add to List

Share
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.



Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


Constraints:

1 <= m, n <= 100
*/

#include <bits/stdc++.h>
using namespace std;
// Brute force
//->We have mxn blocks
//->At each block we have two options
//->Either move down or right
//->Hence TC O(2^(M*N))

//->SC O(M+N)
// Simple use the recusrion
class Solution
{
public:
    // TIME LIMIT EXCEEDED
    int helper(int i, int j, int m, int n)
    {

        // Check if we reached to end of the grid.
        // If so return 1 as path is valid
        if (i == m - 1 && j == n - 1)
            return 1;

        // If w ehave exceeded the bounds, that means no path
        // hence return zero
        if (i >= m || j >= n)
            return 0;

        // Else lets traverse to bottom or ight
        // And return the total paths we are getting from
        // right and bottom blocks to the end block

        int left = helper(i + 1, j, m, n);  // MOVE DOWN
        int right = helper(i, j + 1, m, n); // MOVE RIGHT

        // Retrurn total paths from left and right
        return left + right;
    }
    int uniquePaths(int m, int n)
    {

        return helper(0, 0, m, n);
    }
};

// OPTIMISED: MEMOIZATION
// TC - > For each of i,j pair we call recusrion function only once
//        even for base cases time is constant as we directly return 1 or 0
// TC - > O(M*N) as there are M*N blocks and for each block we call function only once
// SC - > We need a dp of size M*N as there are M*N blocks
//        also we need stack space of O(M+N) as we move along row or column at a time
// SC - > O((M*N)+(M+N))

class Solution
{
public:
    int helper(int i, int j, int m, int n, vector<vector<int>> &dp)
    {

        // Check if we reached to end of the grid.
        // If so return 1 as path is valid
        if (i == m - 1 && j == n - 1)
            return 1;

        // If w ehave exceeded the bounds, that means no path
        // hence return zero
        if (i >= m || j >= n)
            return 0;

        // If i and j are valid, and we had calculated value/ans
        // correspondimng to i,j
        // Henc ethere is no need to calculate again by calling recursion
        if (dp[i][j])
            return dp[i][j];

        // Else lets traverse to bottom or ight
        // And return the total paths we are getting from
        // right and bottom blocks to the end block

        int left = helper(i + 1, j, m, n, dp);  // MOVE DOWN
        int right = helper(i, j + 1, m, n, dp); // MOVE RIGHT

        // Save the answer in dp, to avoid recalculation
        dp[i][j] = left + right;

        // Retrurn total paths from left and right
        return left + right;
    }
    int uniquePaths(int m, int n)
    {
        // From previous brute force
        // If we draw tree we can clealy see that
        // many of m[i][j]  combos are repeating
        // Hence we can definitely used dp

        vector<vector<int>> dp(m, vector<int>(n, 0));
        return helper(0, 0, m, n, dp);
    }
};

// Optimised Tabulation
//  TC ->  O(M*N) asItertating for each of M*N blocks
//  SC ->  O(M*N) as dp of this size is being used
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // Lets try tabulation

        // AS we saw in recursive memoization that
        // we nalwayts need m[0][0]=1 always
        // i.e as we reach to 0,0 from m-1,n-1
        // we return 1

        // Hence in dp. we can set dp[0][0]=1
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        // Now sincew e are moving from bottom to up
        // For reaching block, we nee dto chekc
        // if that block is reachable from 00
        // This can be checked by checking top and left block

        // say we have the matrix
        //  [][][]
        //  [][][]
        //  [][][]

        // Initialisation
        //  [1] [1] [] //we can reach 01 by 1 way from left block([00]) hence [01]=1
        //  []  []  []
        //  []  []  []

        // [1] [1] [1] //we can reach 02 by 1 way from left block([01]) hence [02]=1
        // [ ] [ ] [ ]
        // [ ] [ ] [ ]

        // [1] [1] [1]
        // [1] [ ] [ ] //we can reach 10 by 1 way from top block([00]) hence [10]=1
        // [ ] [ ] [ ]

        // [1] [1] [1]
        // [1] [2] [ ] //we can reach 11 by 2 ways 01 WAY FROM top block([01]) and
        // [ ] [ ] [ ] //01 WAY FROM left block([10]) hence [11]=2

        // [1] [1] [1]
        // [1] [2] [3] //we can reach 12 by 3 ways 01 WAYS FROM top block([01]) and
        // [ ] [ ] [ ] //02 WAYS FROM left block([10]) hence [12]=3

        //[1] [1] [1]
        // [1] [2] [3] //we can reach 20 by 1 way 01 WAY FROM top block([10]) and
        // [1] [ ] [ ] //hence [20]=1

        // [1] [1] [1]
        // [1] [2] [3] //we can reach 21 by 3 ways 02 WAYS FROM top block([11]) and
        // [1] [3] [ ] //01 WAYS FROM left block([20]) hence [21]=3

        // [1] [1] [1]
        // [1] [2] [3] //we can reach 22 by 6 ways 03 WAYS FROM top block([12]) and
        // [1] [3] [ ] //03 WAYS FROM left block([21]) hence [22]=6

        // Since we know that 0th row and 0th column will always be 1
        // Henc initialisation
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;

        // Lets iterate through each of the remaining blocks
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                // Ways to reach current [i][j] block
                // Is equal to number of ways to reach top block [i-1][j]
                // and number of ways to reach left block [i][j-1]
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        // return the nas
        return dp[m - 1][n - 1];
    }
};

//SPACE OPTIMIZATION
// TC ->  O(M*N) asItertating for each of M*N blocks
// SC ->  O(2N) as dp of this size is being used
class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        // say we have the matrix
        //  [][][]
        //  [][][]
        //  [][][]

        // Initialisation
        //  [1] [1] [] //we can reach 01 by 1 way from left block([00]) hence [01]=1
        //  []  []  []
        //  []  []  []

        // [1] [1] [1] //we can reach 02 by 1 way from left block([01]) hence [02]=1
        // [ ] [ ] [ ]
        // [ ] [ ] [ ]

        // [1] [1] [1]
        // [1] [ ] [ ] //we can reach 10 by 1 way from top block([00]) hence [10]=1
        // [ ] [ ] [ ]

        // [1] [1] [1]
        // [1] [2] [ ] //we can reach 11 by 2 ways 01 WAY FROM top block([01]) and
        // [ ] [ ] [ ] //01 WAY FROM left block([10]) hence [11]=2

        // [1] [1] [1]
        // [1] [2] [3] //we can reach 12 by 3 ways 01 WAYS FROM top block([01]) and
        // [ ] [ ] [ ] //02 WAYS FROM left block([10]) hence [12]=3

        //[1] [1] [1]
        // [1] [2] [3] //we can reach 20 by 1 way 01 WAY FROM top block([10]) and
        // [1] [ ] [ ] //hence [20]=1

        // [1] [1] [1]
        // [1] [2] [3] //we can reach 21 by 3 ways 02 WAYS FROM top block([11]) and
        // [1] [3] [ ] //01 WAYS FROM left block([20]) hence [21]=3

        // [1] [1] [1]
        // [1] [2] [3] //we can reach 22 by 6 ways 03 WAYS FROM top block([12]) and
        // [1] [3] [ ] //03 WAYS FROM left block([21]) hence [22]=6

        // Since we know that 0th row and 0th column will always be 1
        // Henc initialisation

        // We can space optimise this solution
        // HOW?
        // At each point of time we just need left and top
        // Hence TOP we can keep in 1-D array
        // Left we can have in current array
        // As curr[0]=1 always
        // Hence iterations can be started from index=1
        // Hence formula is: curr[i]=    curr[i-1]+prev[i];
        //                                   ^       ^
        //                                   |       |
        // ways to reach this block from    LEFT    TOP

        // form top array
        // as we know in row-0 all elemnts are one
        vector<int> prev(n, 1);

        // Lets iterate for remaining rows
        for (int i = 1; i < m; i++)
        {
            vector<int> temp(n, 0);
            // For 0th column each block can be recahed in 01 WAY from TOP
            temp[0] = 1;
            // Iterate for remaing blocks by using LEFT given by temp
            // And top given by prev
            for (int j = 1; j < n; j++)
            {
                temp[j] = temp[j - 1] + prev[j];
            }
            // update prev to use it for next row
            prev = temp;
        }
        return prev[n - 1];
    }
};