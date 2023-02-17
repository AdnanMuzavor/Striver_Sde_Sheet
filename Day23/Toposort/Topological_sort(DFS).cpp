#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void toposort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    // Making node as visisted
    vis[node] = 1;
    // If possible to traverse adjacent that is node-> adjacentnode
    //                                           u        v
    // stack it should be: u
    //                     v
    // Hence v being adjacent should be pushed first
    for (auto e : adj[node])
    {
        if (!vis[e])
        {
            toposort(e, vis, st, adj);
        }
    }
    // As decided above after pushing adjacent node, we'll be pushing current node
    st.push(node);
}

int main()
{
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<int> adj[n + 1];
    for (int i = 1; i <= e; i++)
    {
        int node, adjnode;
        cout << "Enter node: ";
        cin >> node;
        cout << "Enter adjacent node: ";
        cin >> adjnode;
        adj[node].push_back(adjnode);
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " -> ";
        for (auto e : adj[i])
            cout << e << " ";
        cout << endl;
    }

    // Doing topological sort by traversing each element
    vector<int> vis(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            toposort(i, vis, st, adj);
        }
    }

    cout << endl;
    vector<int> op;
    // Getting elements from stack
    while (!st.empty())
    {
        op.push_back(st.top());
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}