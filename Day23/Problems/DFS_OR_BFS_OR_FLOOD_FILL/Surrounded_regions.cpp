/*

130. Surrounded Regions
Medium
6.6K
1.4K
Companies
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Example 1:


Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.
Example 2:

Input: board = [["X"]]
Output: [["X"]]


Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int x, int y, int r, int c, vector<vector<char>> grid, vector<vector<int>> &vis)
    {
        vis[x][y] = 1;
        int d1[4] = {0, 1, -1, 0};
        int d2[4] = {1, 0, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = x + d1[i];
            int ny = y + d2[i];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c || grid[nx][ny] == 'X' || vis[nx][ny])
                continue;
            dfs(nx, ny, r, c, grid, vis);
        }
    }
    void solve(vector<vector<char>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis(r, vector<int>(c, 0));
        // We can start from the border and take a visit to All Os
        //  => All those whom we are able to visit from border are the ones
        //  => which are never ever going to be covered with x along all 4 sides
        //  => while all other O's can be Xed

        // queue<pair<int,int>> q;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {

                if ((j == 0 || i == 0 || j == c - 1 || i == r - 1) && grid[i][j] == 'O' && !vis[i][j])
                {
                    //   q.push({i,j});
                    // vis[i][j]=1;
                    dfs(i, j, r, c, grid, vis);
                }
            }
        }

        // 2)
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (!vis[i][j])
                {
                    grid[i][j] = 'X';
                }
            }
        }
    }
};