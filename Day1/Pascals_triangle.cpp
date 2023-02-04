/*
118. Pascal's Triangle
Easy

7495

247

Add to List

Share
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:




Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]


Constraints:

1 <= numRows <= 30
*/

#include <bits/stdc++.h>
using namespace std;

// SC -> O(num_rows^2)

// TC -> O(num_rows^2)

vector<vector<long long int>> printPascal(int n)
{
    // This is more likem a pattern
    //  r=0                 00              |             1
    //  r=1               10  11            |          1     1
    //  r=2            20   21   22         |       1     2     1
    //  r=3        30    31    32    33     |    1    3      3     1
    //  r=4     40    41    42    43    44  | 1    4      6     4     1

    // Hence wecan jump to conclusion that
    // Initially for rth row
    // 1)set first and last elemnts to 1      ->temp[0]=1, temp[r]=1
    // 2)traverse from for(int i=1;i<r;i++)
    // 3)Use formula   temp[i]=ans[i-1][i-1]+ans[i-1][i]

    // example if we finished row 2, now at row 3
    // hence ans last has row=02
    // current r=3
    // STEP1 temp[0]=1, temp[3]=1   -> 1 [] [] 1

    // STEP2 for(int i=1;i<r;i++)   ->for(int i=1;i<3;i++)

    // STEP3 formula temp[i]=ans[r-1][i-1]+ans[r-1][i]

    // i=1 -> temp[1]=ans[2][0]+ans[2][1] = 1+2 = 3
    // o/p -> 1 3 [] 1
    // i=2 -> temp[2]=ans[2][1]+ans[2][2] = 2+1 = 3
    // o/p -> 1 3 3 1

    // Hence 3rd row is 1 3 3 1

    // Lets implement it
    // Declare solution vector
    vector<vector<long long int>> soln;

    // Traverse for rest of the n values
    for (int r = 0; r < n; r++)
    {
        vector<long long int> temp(r + 1, 0);
        // STEP-1
        temp[0] = 1;
        temp[r] = 1;
        // STEP-2
        for (int i = 1; i < r; i++)
        {
            // STEP-3
            temp[i] = soln[r - 1][i - 1] + soln[r - 1][i];
        }
        // Push ans in solution
        soln.push_back(temp);
    }
    return soln;
}
