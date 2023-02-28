/*

Shortest Distance in a Binary Maze
MediumAccuracy: 58.22%Submissions: 22K+Points: 4
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right.

Example 1:

Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the
shortest path from source to destination cell.
Example 2:

Input:
grid[][] = {{1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1}}
source = {0, 0}
destination = {3, 4}
Output:
-1
Explanation:
The path is not possible between source and
destination, hence return -1.
Your Task:

You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a 2D integer array grid, source cell and destination cell as an input parameters and returns the shortest distance between source and destination cell.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:

1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
The source and destination cells are always inside the given matrix.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> des)
    {
        // code here
        int sx = source.first;
        int sy = source.second;
        int dx = des.first;
        int dy = des.second;
        int r = grid.size();
        int c = grid[0].size();
        // => If source itself has zero or destination has zero value
        // => then it's never possible to reach to destination
        if (grid[sx][sy] == 0 || grid[dx][dy] == 0)
            return -1;

        int steps = INT_MAX;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(r, vector<int>(c, 0));
        // We start from source with zero distance steps taken as yet
        q.push({0, {sx, sy}});
        while (!q.empty())
        {
            auto tp = q.front();
            q.pop();
            int step_count = tp.first;
            int x = tp.second.first;
            int y = tp.second.second;
            // Check if we reach destination
            if (x == dx && y == dy)
            {
                // Avoid stesp to have minimum steps
                steps = min(steps, step_count);
                // No need to tru next 4 directions as we are already at destination
                break;
            }

            // else try visiting surrounding 4 directions
            int d1[4] = {0, -1, 1, 0};
            int d2[4] = {1, 0, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newx = x + d1[i];
                int newy = y + d2[i];
                if (newx < 0 || newy < 0 || newx >= r || newy >= c || vis[newx][newy] || grid[newx][newy] == 0)
                    continue;
                vis[newx][newy] = 1;
                q.push({step_count + 1, {newx, newy}});
            }
        }
        return steps == INT_MAX ? -1 : steps;
    }
};