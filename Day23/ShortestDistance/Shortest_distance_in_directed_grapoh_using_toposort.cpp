//DIRECTED ACYCLIC GRAPH using Toposort
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//TC:O(2(N+E)) 1 for toposort ,other to find distance

//SC:O(N+N) Distance array, stack space
void toposort(vector<pair<int, int>> adj[], int node, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto e : adj[node])
    {
        if (!vis[e.first])
        {
            toposort(adj, e.first, vis, st);
        }
    }
    st.push(node);
}
// Shortest Du=istance using BFS
void ShortDisFromSrc(int n, vector<pair<int, int>> adj[], int src)
{
    // Stack for finding toposort
    stack<int> st;
    // Visisted vector to help in toposort
    vector<int> vis(n + 1, 0);
    // Finding toposort
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            toposort(adj, i, vis, st);
        }
    }

    // Making distance vector initialiased with maximum distance
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0; // Distance of node form node itself is zero

    while (!st.empty())
    {
        // Getting current nodes
        int node = st.top();
        st.pop();
        // Checking if node is visisted i.e distance of node is not INT_MAX
        if (dist[node] != INT_MAX)
        {
            // Visiting adjacent nodes
            for (auto e : adj[node])
            {
                // If through current node, resultant distance is lesser
                // thn distance of node in distance array thn we update it
                if (dist[node] + e.second < dist[e.first])
                {
                    dist[e.first] = dist[node] + e.second;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "distance of " << i << " from " << src << " is: " << dist[i] << endl;
    }
}

int main()
{

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cout << "Enter node: ";
        cin >> u;
        cout << "Enter adjacent node: ";
        cin >> v;
        cout << "Enter weight of egde: ";
        cin >> wt;
        adj[u].push_back({v, wt});
    }
    for (int i = 0; i < n; i++)
    {
        cout << "node is: " << i << " adj are: ";
        for (auto e : adj[i])
            cout << e.first << " at dist of: " << e.second << "  from " << i << endl;
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << "Giving src as: " << i << endl;
        ShortDisFromSrc(n, adj, i);
    }
    return 0;
}
