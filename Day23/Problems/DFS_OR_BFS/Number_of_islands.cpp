/*
200. Number of Islands
Medium
18.9K
421
Companies
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.



Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        // Keep track of visisted islands
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int ans = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // If current cell is land and was noyt visited
                if (grid[i][j] == '1' && vis[i][j] == 0)
                {
                    // Vissiting entire island starting from and her eand making it's cells visited
                    cout << "visiting: " << i << ", " << j << endl;
                    queue<pair<int, int>> q;
                    vis[i][j] = 1;
                    q.push({i, j});
                    // Visiting all cells of then island
                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        if (x - 1 >= 0 && grid[x - 1][y] == '1')
                        {
                            if (vis[x - 1][y] == 0)
                            {

                                q.push({x - 1, y});
                                vis[x - 1][y] = 1;
                            }
                        }
                        if (x + 1 < rows && grid[x + 1][y] == '1')
                        {
                            if (vis[x + 1][y] == 0)
                            {

                                q.push({x + 1, y});
                                vis[x + 1][y] = 1;
                            }
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1')
                        {
                            if (vis[x][y - 1] == 0)
                            {

                                q.push({x, y - 1});
                                vis[x][y - 1] = 1;
                            }
                        }
                        if (y + 1 < cols && grid[x][y + 1] == '1')
                        {
                            if (vis[x][y + 1] == 0)
                            {

                                q.push({x, y + 1});
                                vis[x][y + 1] = 1;
                            }
                        }
                    }
                    // As we visited 1 island we increment ans by 1
                    ans += 1;
                }
            }
        }
        return ans;
    }
};