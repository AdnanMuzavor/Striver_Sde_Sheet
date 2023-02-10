/*
Rat in a Maze Problem - I
MediumAccuracy: 35.75%Submissions: 100k+Points: 4
Lamp
This problem is part of GFG SDE Sheet. Click here to view more.

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

Example 1:

Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1},
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at
(3, 3) from (0, 0) by two paths - DRDDRR
and DDRDRR, when printed in sorted order
we get DDRDRR DRDDRR.
Example 2:
Input:
N = 2
m[][] = {{1, 0},
         {1, 0}}
Output:
-1
Explanation:
No path exists and destination cell is
blocked.
Your Task:
You don't need to read input or print anything. Complete the function printPath() which takes N and 2D array m[ ][ ] as input parameters and returns the list of paths in lexicographically increasing order.
Note: In case of no path, return an empty list. The driver will output "-1" automatically.

Expected Time Complexity: O((3N^2)).
Expected Auxiliary Space: O(L * X), L = length of the path, X = number of paths.

Constraints:
2 ≤ N ≤ 5
0 ≤ m[i][j] ≤ 1
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<string> op;
    void helper(int i, int j, vector<vector<int>> vis, vector<vector<int>> m, int r, int c, string soln)
    {
        // cout<<i<<" "<<j<<endl;
        // Base case(Reaching the destination)
        if (i == r - 1 && j == c - 1)
        {
            op.insert(soln);
            return;
        }

        // Keep the four directions
        char directions[] = {'R', 'D', 'U', 'L'};
        int d1[] = {0, 1, -1, 0};
        int d2[] = {1, 0, 0, -1};

        // Try each direction if valid
        for (int d = 0; d < 4; d++)
        {

            int x, y;
            x = i + d1[d];
            y = j + d2[d];
            // Validate x and y coordinates
            if (x >= r || x < 0 || y >= c || y < 0 || m[x][y] == 0 || vis[x][y])
                continue;
            vis[x][y] = 1; // Marking x and y visisted so that same blocks cannot be visisted again
            helper(x, y, vis, m, r, c, soln + directions[d]);
            vis[x][y] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        // Base case
        vector<string> sol;
        int r = m.size();
        int c = m[0].size();

        // Base case
        // If start point itself has obstacke(0) ||
        /// End point itr self has obstcale ther eis no use finding the path
        if (m[0][0] == 0 || m[r - 1][c - 1] == 0)
            return sol;

        vector<vector<int>> vis(r, vector<int>(c, 0));
        vis[0][0] = 1;
        string soln = "";

        helper(0, 0, vis, m, r, c, soln);

        for (auto e : op)
            sol.push_back(e);
        return sol;
    }
};