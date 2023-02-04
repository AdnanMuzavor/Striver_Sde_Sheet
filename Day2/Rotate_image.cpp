/*
48. Rotate Image
Medium

10993

545

Add to List

Share
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]


Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/
#include <bits/stdc++.h>
using namespace std;
// Brute force
// O(N*N)+O(N*N)

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // If you clealry see
        // 1)Last row of matrix is first column of rotated matrix
        // 2)First row itself is last column  of raoated matrix

        // Hence from given matrix we need to create such matrix
        // Hence we can use the extra space
        int n = matrix.size();
        vector<vector<int>> soln(n, vector<int>(n, 0));

        // set col to n-1
        // as last column will have first row elements
        int col = n - 1;

        // Lets make each row of matrix column of soln matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                soln[j][col] = matrix[i][j];
            }
            col--;
        }

        // Lets copy solution of original matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = soln[i][j];
            }
        }
    }
};
// Optimised
// O(N*N)+O(1)

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // We can jump to conlcusion that
        // We can follow a certain procedure based on pattern
        // 1)Take the transpose on matrix
        // 2)Then reverse each of the rows of the matrix

        // Take the parameters
        int n = matrix.size();
        int m = matrix[0].size();

        // Take transpose of the matrix
        int i = 0, j = 0;
        while (i < n)
        {
            // Swap ith row and ith column
            int k = i;
            while (k < n)
            {
                swap(matrix[i][k], matrix[k][i]);
                k++;
            }
            // Swap next row and next column,leaving swapped elements unchanged
            i++;
        }

        // Reverse each of the rows
        for (int i = 0; i < n; i++)
        {
            int k = 0, j = n - 1;
            while (k < j)
                swap(matrix[i][k++], matrix[i][j--]);
        }
    }
};