/*

1584. Min Cost to Connect All Points
Medium
3.4K
84
Companies
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.



Example 1:


Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18


Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int ans = 0;
        set<pair<int, int>> st;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        q.push({0, {points[0][0], points[0][1]}});
        while (!q.empty())
        {
            auto tp = q.top();
            q.pop();
            int x = tp.second.first;
            int y = tp.second.second;
            if (st.find({x, y}) != st.end())
                continue;
            st.insert({x, y});
            ans += tp.first;
            for (auto p : points)
            {
                int nx = p[0], ny = p[1];
                if (st.find({nx, ny}) == st.end())
                {
                    q.push({(abs(x - nx) + abs(y - ny)), {nx, ny}});
                }
            }
        }
        return ans;
    }
};