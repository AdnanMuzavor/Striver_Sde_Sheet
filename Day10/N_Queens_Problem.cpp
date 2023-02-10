/*
51. N-Queens
Hard

8621

193

Add to List

Share
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.



Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]


Constraints:

1 <= n <= 9
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int diagonal(int colno, int row, vector<string> bd, int n)
    {

        // Four diagonal cases to be checked
        /*
            \    /
             \  /
              \/
              /\
             /  \
            /    \

        */

        int x = row, y = colno;
        // Checking upper diagonal LHS
        /*
         \
          \
           \
            chosen_pos
        */
        while (x >= 0 && y >= 0)
        {
            if (bd[x][y] == 'Q')
                return 1;
            x--;
            y--;
        }

        x = row, y = colno;
        // Checking lower diagonal RHS
        /*
        chosen_pos
                  \
                   \
                    \
    */
        while (x < n && y < n)
        {
            if (bd[x][y] == 'Q')
                return 1;
            x++;
            y++;
        }
        // Checking upper diagonal RHS
        x = row, y = colno;
        /*
               /
              /
             /
    chosen_pos


*/
        while (x >= 0 && y < n)
        {
            if (bd[x][y] == 'Q')
                return 1;
            x--;
            y++;
        }

        // Checking lower diagonal LHS
        x = row, y = colno;
        /*

   chosen_pos
   /
  /
 /


*/
        while (x < n && y >= 0)
        {
            if (bd[x][y] == 'Q')
                return 1;
            x++;
            y--;
        }
        return 0;
    }
    void helper(vector<vector<string>> &op, vector<string> bd, vector<int> col, int row, int n)
    {
        // If we reach till last row => meansw  eplaced all the queens
        if (row == n)
        {
            op.push_back(bd);
            return;
        }
        // Iterate through each of columns and see if w ecan place the queens there
        for (int c = 0; c < n; c++)
        {
            // If this column was not previsly fille diwtgh any queen
            if (!col[c])
            {
                // Check for diagonals
                if (!diagonal(c, row, bd, n))
                {
                    // Place the queen here
                    bd[row][c] = 'Q';
                    // Mark column as occupied
                    col[c] = 1;
                    // Iteare for next row with this data
                    helper(op, bd, col, row + 1, n);
                    // For next ietration, remobv ethe queeen to try othe rways
                    bd[row][c] = '.';
                    col[c] = 0;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> op; // To push the output
        vector<string> bd;         // Our borad where we shall be placing the queens
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            bd.push_back(s);
        }
        vector<int> coln(n, 0); // To find out in which columns have we placed the queens
        helper(op, bd, coln, 0, n);
        return op;
    }
};