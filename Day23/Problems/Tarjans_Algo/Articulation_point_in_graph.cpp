/*
Articulation Point - I
HardAccuracy: 39.26%Submissions: 25K+Points: 8
Participate in Monthly Hiring Challenge conducted by GeeksforGeeks !!

Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:

Input:

Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-

Removing the vertex 4 will disconnect the
graph as-



Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V ≤ 105
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
    int timer = 0;

    void dfs(int node, int p, vector<int> &vis, vector<int> adj[], int time[], int lowtime[], vector<int> &aps)
    {
        vis[node] = 1;
        time[node] = timer;
        lowtime[node] = timer;
        timer++;
        int child = 0;
        for (auto adjn : adj[node])
        {
            if (adjn == p)
                continue;
            // Case 1 Not visited
            if (!vis[adjn])
            {
                dfs(adjn, node, vis, adj, time, lowtime, aps);
                lowtime[node] = min(lowtime[node], lowtime[adjn]);
                if (lowtime[adjn] >= time[node] && p != -1)
                {
                    // node is articulation point
                    aps[node] = 1;
                }
                child++;
            }
            // Case 2 visited
            else
            {
                lowtime[node] = min(lowtime[node], time[adjn]);
            }
        }

        // Incase parent itself has multiple children then it itself can become articulation point
        if (child > 1 && p == -1)
            aps[node] = 1;
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here
        vector<int> aps(V, 0); // aps[i]=1 means i is articulation point
        // We need same prerequisites as Tarjans algo
        int time[V];
        int lowtime[V];

        // Find the articulation points
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, adj, time, lowtime, aps);
            }
        }

        // Add the points to op
        vector<int> op;
        bool atleast_one = false;
        for (int i = 0; i < V; i++)
        {
            if (aps[i] == 1)
            {
                op.push_back(i);
                atleast_one = true;
            }
        }

        // If no points, add -1 into op
        if (!atleast_one)
            op.push_back(-1);
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
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends