/*

Negative weight cycle
MediumAccuracy: 41.9%Submissions: 46K+Points: 4
Lamp
Don't Miss Out on the Chance to Work with Leading Companies! Visit the GFG Job Fair Now!

Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.
Note: edges[i] is defined as u, v and weight.


Example 1:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
Output: 1
Explanation: The graph contains negative weight
cycle as 0->1->2->0 with weight -1,-2,-3.
Example 2:

Input: n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
Output: 0
Explanation: The graph does not contain any
negative weight cycle.


Your Task:
You don't need to read or print anyhting. Your task is to complete the function isNegativeWeightCycle() which takes n and edges as input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.


Expected Time Complexity: O(n*m)
Expected Space Compelxity: O(n)


Constraints:
1 <= n <= 100
1 <= m <= n*(n-1), where m is the total number of Edges in the directed graph.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isNegativeWeightCycle(int V, vector<vector<int>> edges)
    {
        vector<int> dist(V, 100000000);
        dist[0] = 0;
        int n = V - 1;
        // Do [no_of_nodes - 1] relaxations
        while (n--)
        {
            for (auto e : edges)
            {
                int from = e[0];
                int to = e[1];
                int wt = e[2];
                if (dist[to] > dist[from] + wt)
                {
                    dist[to] = dist[from] + wt;
                }
            }
        }

        // Do nth relaxation, checking for negative cycle
        for (auto e : edges)
        {
            int from = e[0];
            int to = e[1];
            int wt = e[2];
            if (dist[to] > dist[from] + wt)
            {

                return 1;
            }
        }

        return 0;
    }
};