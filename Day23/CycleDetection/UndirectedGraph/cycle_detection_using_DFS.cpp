/*
To detect cycle in undirected graph using DFS
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool detectCycleDFS(int prev, int node, vector<int> &vis, vector<int> adj[])
{

    // => mARK CURRENT NODE AS VISITED
    vis[node] = 1;
    // => CHECK FOR EEACH OF ADJACENT NODE
    for (auto adjnode : adj[node])
    {
        // => IF FOUND NODE VISISTED THAT SHOULD AHVE BEEN A PREV NODE
        // => IF NODE IS NOT PREV STILL VISISTED MEANS CYCLE EXISTS!!
        if (vis[adjnode] && adjnode != prev)
            return true;
        // => IF NO CYCLE FOUND , THEN GO AHEAD IN DEPTH FIRST SEARCH
        // => AND CHECK FOR CURRENT NODE'S ADJACENT TAKING CURRENT NODE AS PREV.
        else if (!vis[adjnode] && detectCycleDFS(node, adjnode, vis, adj))
            return true;
    }
    return false;
}
int main()
{
    int n, e;
    cout << "Enter number of nodes: " << endl;
    cin >> n;
    cout << "Enter number of edges: " << endl;
    cin >> e;
    vector<int> adj[n];
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < e; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
        adj[to].push_back(from); // As undirected graph it is
    }
    cout << "Graph is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " node: " << i << " ";
        for (auto e : adj[i])
        {
            cout << " | " << e << " | ";
        }
        cout << endl;
    }
    vector<int> vis(n, 0);
    if (detectCycleDFS(-1, 0, vis, adj))
    {
        cout << "Cycle exists in given graph" << endl;
    }
    else
    {
        cout << " No cycle in the graph" << endl;
    }
    return 0;
}