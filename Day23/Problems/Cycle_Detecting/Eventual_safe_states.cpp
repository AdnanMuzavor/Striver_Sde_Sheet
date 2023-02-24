/*
802. Find Eventual Safe States
Medium
3.4K
350
Companies
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.



Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.


Constraints:

n == graph.length
1 <= n <= 104
0 <= graph[i].length <= n
0 <= graph[i][j] <= n - 1
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 104].
Accepted
116.4K
Submissions
207K
Acceptance Rate
56.2%
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool cycle(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &dfsvis, vector<int> &check)
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        check[node] = 0; // Assume it's not safe
        for (auto adjnode : graph[node])
        {
            if (!vis[adjnode])
            {
                if (cycle(adjnode, graph, vis, dfsvis, check))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else if (dfsvis[adjnode])
            {
                check[node] = 0;
                return true;
            }
        }
        // => REACHING HERE MEANS == NO_CYCLE
        // => Hence node is safe node
        check[node] = 1;
        dfsvis[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        vector<int> op;
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> dfsvis(n, 0);
        vector<int> check(n, 0); // If check[node]=1, node is SAFE
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {

                cycle(i, graph, vis, dfsvis, check);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (check[i])
            {
                op.push_back(i);
            }
        }
        return op;
    }
};