// Cycle in DIRECTED GRAPH using BFS
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Using Kahn's alogorithm
bool iscycle(int n, vector<int> adj[])
{
    cout << "In fn" << endl;
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto e : adj[i])
        {
            indeg[e]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto e : adj[node])
        {
            indeg[e]--;
            if (indeg[e] == 0)
            {
                q.push(e);
            }
        }
    }
    cout << "n is: " << n << endl;
    cout << "count is: " << count << endl;
    if (count == n)
        return false;
    return true;
}

int main()
{

    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter node: ";
        cin >> u;
        cout << "Enter adjacent node: ";
        cin >> v;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        cout << "node is: " << i << " adj are: ";
        for (auto e : adj[i])
            cout << e << " ";
        cout << endl;
    }
    if (iscycle(n, adj))
    {
        cout << "Graph is cyclic" << endl;
    }
    else
    {
        cout << "Graph is not cyclic" << endl;
    }
    return 0;
}
