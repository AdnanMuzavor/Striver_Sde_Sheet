/*
Distance of nearest cell having 1
MediumAccuracy: 47.7%Submissions: 46K+Points: 4
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.


Example 1:

Input: grid = {{0,1,1,0},{1,1,0,0},{0,0,1,1}}
Output: {{1,0,0,1},{0,0,1,1},{1,1,0,0}}
Explanation: The grid is-
0 1 1 0
1 1 0 0
0 0 1 1
0's at (0,0), (0,3), (1,2), (1,3), (2,0) and
(2,1) are at a distance of 1 from 1's at (0,1),
(0,2), (0,2), (2,3), (1,0) and (1,1)
respectively.


Example 2:

Input: grid = {{1,0,1},{1,1,0},{1,0,0}}
Output: {{0,1,0},{0,0,1},{0,1,2}}
Explanation: The grid is-
1 0 1
1 1 0
1 0 0
0's at (0,1), (1,2), (2,1) and (2,2) are at a
distance of 1, 1, 1 and 2 from 1's at (0,0),
(0,2), (2,0) and (1,1) respectively.




Yout Task:
You don't need to read or print anything, Your task is to complete the function nearest() which takes the grid as an input parameter and returns a matrix of the same dimensions where the value at index (i, j) in the resultant matrix signifies the minimum distance of 1 in the matrix from grid[i][j].


Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/

#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        // Code here
        int r = grid.size();
        int c = grid[0].size();

        // Initialise the op
        vector<vector<int>> op(r, vector<int>(c, INT_MAX));

        // Take a queue as we shall be using BFS
        queue<pair<int, int>> q;

        // Lets fidn cells with 1, these are the cells having
        // minimum distance in them, and from these cells only we shall be
        // finding distance for other cell

        // EDGE CASE: IT MAY HAPPEN THAT THERE IS NO 1 AT ALL
        // These can be handled automatically

        int atleast_one_zero = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    op[i][j] = 0;
                    q.push({i, j});
                }
                else
                {
                    atleast_one_zero = 1;
                }
            }
        }
        if (!atleast_one_zero)
            return op;

        // Find minimum distance for other cells now
        while (!q.empty())
        {
            auto tp = q.front();
            q.pop();
            int x = tp.first;
            int y = tp.second;

            if (x + 1 < r && grid[x + 1][y] != 1)
            {

                if (op[x][y] + 1 < op[x + 1][y])
                {
                    op[x + 1][y] = op[x][y] + 1;

                    q.push({x + 1, y});
                }
            }
            if (y + 1 < c && grid[x][y + 1] != 1)
            {

                if (op[x][y] + 1 < op[x][y + 1])
                {
                    op[x][y + 1] = op[x][y] + 1;

                    q.push({x, y + 1});
                }
            }
            if (x - 1 >= 0 && grid[x - 1][y] != 1)
            {

                if (op[x][y] + 1 < op[x - 1][y])
                {
                    op[x - 1][y] = op[x][y] + 1;

                    q.push({x - 1, y});
                }
            }
            if (y - 1 >= 0 && grid[x][y - 1] != 1)
            {

                if (op[x][y] + 1 < op[x][y - 1])
                {
                    op[x][y - 1] = op[x][y] + 1;

                    q.push({x, y - 1});
                }
            }
        }

        return op;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        vector<vector<int>> ans = obj.nearest(grid);
        for (auto i : ans)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends