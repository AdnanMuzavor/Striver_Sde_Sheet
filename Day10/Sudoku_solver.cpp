/*

37. Sudoku Solver
Hard

6783

183

Add to List

Share
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.



Example 1:


Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:




Constraints:

board.length == 9
board[i].length == 9
board[i][j] is a digit or '.'.
It is guaranteed that the input board has only one solution.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool tryplacing(vector<vector<char>> &board)
    {

        // Iterate the blocks
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // If current block is empty, try placing chars in it
                // from 1- 9 only if placing such char is valid
                // as given by valid function
                if (board[i][j] == '.')
                {
                    for (int ch = '1'; ch <= '9'; ch++)
                    {

                        // Check if it's valid to put this char
                        // I.e no elemnt in entir erow and entire column
                        // should have the same value
                        if (isvalid(board, ch, i, j))
                        {

                            // Place the lemnt and try for next empty block
                            // by calling recursive function
                            board[i][j] = ch;
                            if (tryplacing(board) == true)
                            {
                                return true; // To avoid any more iterations
                            }
                            else
                            {
                                // Unplace the elemnt, to try next possible char
                                board[i][j] = '.';
                            }
                        }
                    }
                    // Non of 9 could be placed, so no point in iterating ahead
                    return false;
                }
            }
        }
        return true; // Reaching here indicates, no possible solutions
    }
    bool isvalid(vector<vector<char>> board, char ch, int r, int c)
    {
        for (int i = 0; i < 9; i++)
        {
            // If any elemnt is same row a=has same value
            if (board[r][i] == ch)
                return false;
            // if nay elemnt in column has same value
            if (board[i][c] == ch)
                return false;
            // if any elemnt in 3x3 subboxes has same value
            if (board[3 * (r / 3) + (i / 3)][3 * (c / 3) + (i % 3)] == ch)
                return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        // We need to solve the board, so for current block we find empty
        // and we are successfully able to place elemnent, thn by keeping this new elemnt
        // we should see if we can place the elemnts in other empty blocks, untill
        // the last block is filled fullfilling the sudoku conidtions
        //  -> Hence we use other function wghich will return us boolean
        //  -> If true, we shall proceed to returning the block
        //  -> if false, we shgall make the currentlyt filled blockm empty,
        //  -> and try the next char
        tryplacing(board);
    }
};