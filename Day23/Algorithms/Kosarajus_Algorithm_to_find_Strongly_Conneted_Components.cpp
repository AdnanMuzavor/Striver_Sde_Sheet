/*
Strongly Connected Components (Kosaraju's Algo)
MediumAccuracy: 50.61%Submissions: 54K+Points: 4
Participate in Monthly Hiring Challenge conducted by GeeksforGeeks !!

Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.


Example 1:

Input:

Output:
3
Explanation:

We can clearly see that there are 3 Strongly
Connected Components in the Graph
Example 2:

Input:

Output:
1
Explanation:
All of the nodes are connected to each other.
So, there's only one SCC.


Your Task:
You don't need to read input or print anything. Your task is to complete the function kosaraju() which takes the number of vertices V and adjacency list of the graph as inputs and returns an integer denoting the number of strongly connected components in the given graph.


Expected Time Complexity: O(V+E).
Expected Auxiliary Space: O(V).


Constraints:
1 ≤ V ≤ 5000
0 ≤ E ≤ (V*(V-1))
0 ≤ u, v ≤ N-1
*/

#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    stack<int> SCC_order;
    void dfs(vector<vector<int>> adj, int node, vector<int> &vis, bool push)
    {
        vis[node] = 1;
        for (auto adj_node : adj[node])
        {

            if (!vis[adj_node])
            {

                dfs(adj, adj_node, vis, push);
            }
        }
        if (push)
            SCC_order.push(node);
    }
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>> &adj)
    {

        // //code here
        // Step 01: __Find the order of nodes in SCC__
        //         So that the node in last SCC is pushed first and node in first
        //         SCC is at top of stack so that w eknow from where to start after reversing edges
        vector<int> vis(V, 0);
        dfs(adj, 0, vis, true);

        // Conclusion: Now we know which elemnt is likely to be in our First SCC

        // Step 02: _REVERSE THE EDGES_
        vector<vector<int>> new_adj(V);
        for (int i = 0; i < V; i++)
        {
            for (auto adjn : adj[i])
            {
                //   cout<<adjn<<" ";
                new_adj[adjn].push_back(i);
            }
        }

        // Conclusion : Now we wont be able to go from first SCC to second and so on which could have
        //              increased our work and created confusion

        // Step 02: _Do the DFS_
        int SCC = 0;
        /// Reinitalise the vis
        for (int i = 0; i < V; i++)
            vis[i] = 0;
        // Start dfs from the elemnt at top of stack as it's our first SCC's element
        while (!SCC_order.empty())
        {
            int node = SCC_order.top();
            SCC_order.pop();
            if (!vis[node])
            {
                dfs(new_adj, node, vis, false);
                SCC++;
            }
        }

        // Conclusion: The no of times we did DFS gives the count of SCCs
        return SCC;
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends