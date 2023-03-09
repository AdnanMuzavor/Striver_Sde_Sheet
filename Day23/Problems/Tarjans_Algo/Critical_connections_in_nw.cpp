/*
1192. Critical Connections in a Network
Hard
5.3K
170
Companies
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.



Example 1:


Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:

Input: n = 2, connections = [[0,1]]
Output: [[0,1]]


Constraints:

2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/
#include <bits/stdc++.h>
using namespace std;

// Time Complexity
// => We are doing a dfs HENCE O(V+2E)
// Space Complexity
// => Adj     - > V+2E
// => 3 arrs  - > 3N

class Solution
{
public:
    int timer = 1;
    void dfs(int node, int p, vector<int> &vis, vector<int> adj[], int time[], int lowtime[], vector<vector<int>> &b)
    {
        // Mark node visited
        vis[node] = 1;
        // Set the timers for this node based on global var timer
        time[node] = lowtime[node] = timer;
        // Increment the timer for next node
        timer++;
        // Now traverse the adjacent nodes
        for (auto adjn : adj[node])
        {
            // Avoid parent node
            if (adjn == p)
                continue;
            if (!vis[adjn])
            {
                // Visit it and after you visit, update current node's low time if possible
                dfs(adjn, node, vis, adj, time, lowtime, b);
                lowtime[node] = min(lowtime[node], lowtime[adjn]);
                // Check if edge with this node could be bridge
                if (lowtime[adjn] > time[node])
                {
                    // We foud bridge add it into the braidges
                    vector<int> t(2, 0);
                    t[0] = node;
                    t[1] = adjn;
                    b.push_back(t);
                }
            }
            else
            {
                // If vis, just upfdate the low on it's reference
                lowtime[node] = min(lowtime[node], lowtime[adjn]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        // => This problem is equivalent to finding the brindge in the graph
        // => So if we remove the bridge,servers will be disconnected

        // 1) Making adjacency list
        vector<int> adj[n];
        for (auto edg : connections)
        {
            adj[edg[0]].push_back(edg[1]);
            adj[edg[1]].push_back(edg[0]);
        }

        // 2) Get all the requirements
        vector<int> vis(n, 0);
        int time[n];
        int lowtime[n];
        vector<vector<int>> bridges;

        // 3)Call the function
        dfs(0, -1, vis, adj, time, lowtime, bridges);
        return bridges;
    }
};