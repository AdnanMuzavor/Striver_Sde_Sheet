/*
73. Set Matrix Zeroes
Medium

8647

537

Add to List

Share
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
// Brute force TC O(R*C*(R+C)), SC O(R*C)
// will be to take a row and column value
// such that matrix[row][column]=0
// And all elemnts of same row and column to zero
void helper(vector<vector<int>> &m, vector<vector<int>> &vis, int i, int j, int r, int c)
{
    // Make all rows zero
    for (int k = 0; k < c; k++)
    {
        // If element is already zero
        // we should not mark it visited
        // As purpose of visisted is to help us to differentiate
        // between new and old zeroes

        // WHAT WILL HEPPEN IF WE MARK IT ZERO?
        //->In next iteration,we wont able to make values in rows
        // and columns corresponding to those values=0, hence we'll get wromg             //answer, he we should preserve anew and old zeroes
        if (m[i][k] != 0)
        {
            m[i][k] = 0;
            vis[i][k] = 1;
        }
    }
    // Make all columns also zeroes
    for (int k = 0; k < r; k++)
    {
        if (m[k][j] != 0)
        {
            m[k][j] = 0;
            vis[k][j] = 1;
        }
    }
}

void setZeros(vector<vector<int>> &matrix)
{
    // Traverse netire matrix
    // if matrix[i][j]=0, make ith row and jth column values=0
    int r = matrix.size();
    int c = matrix[0].size();

    // NEED FOR VISISTED MATRIX?
    // We need a visisted matrix
    // Say that we make a particular row and column zero
    // But because of elements recently set to zeroes
    // We should not set other elemnts corresponding to these
    // elements to zeroes
    // i.e zero assigning is only from native values and not any other values
    vector<vector<int>> vis(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // If matrix[i][j]=0 and matrix value is noy visisted
            // Basically visisted helps in differentiating between
            // zeroes which were present and new zeroes
            if (matrix[i][j] == 0 && !vis[i][j])
            {
                vis[i][j] = 1;
                helper(matrix, vis, i, j, r, c);
            }
        }
    }
}

class Solution
{
public:
    // TC O(R*C)
    // SC O(1)
    void setZeroes(vector<vector<int>> &matrix)
    {

        // in  previous solution we had to use a visisted matrix
        // which costs extra space of O(R*C)

        // This appraoch can help us optimise the space
        // and reduce TC from R*C*(R+C) to just R*C

        // Step-1
        // find the elements with zero values, avoid using extra space
        // set first row and first column of this elemnt to zero
        // so that based on rows and columns we can findout which block
        // should be made equal to zero

        // THERE IS PROBLEM
        // By doing so we cannot start setting blocks to zeroes
        // from row-0 and column-0 as 0s in row-0 and column-0 may not be
        // native zeroes hence we might get a wrong answer
        // SOLUTION: Start setting zeroes from row-1 and column-1
        //           by checking if that element's first rowth or first columnth
        //           element is zero

        // WHAT IF 0TH ROW AND COLUMN TOO HAD NATIVE ZEROES?
        // In this case we can use boolean vars say row0 and col0
        // Such that while traversing
        // 1)if we found row-0's element to be zero we'll set
        // row0=TRUE hence later we can make all elemnts of row0=0
        // 2)if we found col-0's element to be zero we'll set
        // col0=TRUE hence later we can make all elemnts of col0=0

        // STEP1:TRAVERSE MATRIX AND SET ROW-0'S AND COL-0'S ELEMENTS TO ZERP
        //       KEEP TRACK IF ZEROTH ROW AND ZEROTH COLUMN ARE ALSO ZERO
        int r = matrix.size(), row0 = 0;
        int c = matrix[0].size(), col0 = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Check if its zeroth row's element
                    // if so,set row0=true =>As we need to set row-0 to zero
                    if (i == 0)
                        row0 = 1;

                    // Check if its zeroth col's element
                    // if so,set col0=true =>As we need to set col-0 to zero
                    if (j == 0)
                        col0 = 1;

                    // Then a sdiscuss set first ith row and first element of jth column to 0
                    matrix[i][0] = 0; // First column element set to zero
                    matrix[0][j] = 0; // First row element set to zero
                }
            }
        }
        // Lets set elements to zero if first row and first column elemnts are zero
        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                // If first row or first column's elements are zero
                // set this element also to zero
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        // Check if first row and first column (0th) are also suppose to be set to zeroes
        if (row0 == 1)
            for (int i = 0; i < c; i++)
                matrix[0][i] = 0;
        if (col0 == 1)
            for (int i = 0; i < r; i++)
                matrix[i][0] = 0;
    }
};