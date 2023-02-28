/*
1631. Path With Minimum Effort
Medium
4K
153
Companies
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.



Example 1:



Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:



Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
Example 3:


Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

*/

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, pair<int, int>>
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &h)
    {
        // Its same as dijkstra where in we have find shortest path
        // between first grid and every grid where max abs diff is
        // edge weight
        // Define directions
        int d1[4] = {0, 1, -1, 0};
        int d2[4] = {-1, 0, 0, 1};

        // Here we need 2d array for saving distances
        int r = h.size(), c = h[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        // We know that distance of first grid will be zero
        dist[0][0] = 0;
        // Lets make priority queue
        // pii is pair of int and pair
        // int-> distance
        // pair part for index (i,j)
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        // Push source block whopse distnace is zero
        pq.push({0, {0, 0}});
        // Lets find minimum path
        while (!pq.empty())
        {
            auto ele = pq.top();
            pq.pop();
            int d = ele.first;
            int i = ele.second.first;
            int j = ele.second.second;
            cout << "Processing " << i << " , " << j << endl;
            if (i == r - 1 && j == c - 1)
                return d;
            // From curent grid, given by i,j
            // find out possible grid to be chosen wrt all for directions
            for (int k = 0; k < 4; k++)
            {
                int x = i + d1[k];
                int y = j + d2[k];
                // Lets validate indices
                if (x < 0 || x >= r || y < 0 || y >= c)
                    continue;
                // Else indices are valid
                // Find max abs diff
                // It can be found by comparfing current grid abs min diff
                // and new grid abs min diff
                int absdiff = max(d, abs(h[i][j] - h[x][y]));

                // If this min diff is lesswer then d, update distance
                if (absdiff < dist[x][y])
                {
                    dist[x][y] = absdiff;
                    pq.push({absdiff, {x, y}});
                }
            }
        }
        return 0;
    }
};
